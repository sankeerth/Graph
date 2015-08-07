#include "primMST.h"
#include "log.h"
#include "../HEAP/HeapFactory.h"
#include <iostream>
#include <limits.h>

PrimMST::PrimMST(Graph *graph, graph_info info)
	: graph(graph)
	, info(info)
	, distance(0)
	, visited(0)
	, parent(0)
{}

PrimMST::~PrimMST()
{
	delete [] distance;
	delete [] visited;
	delete [] parent;
}

void PrimMST::compute()
{
	int nodes = graph->getNodeCount();
	visited = new bool [nodes];
	distance = new int [nodes];
	parent = new int [nodes];

	HeapType type = Min;
	Heap<Node*> *heap = HeapFactory::create<Node*>(type);

	for (int i = 0; i < nodes; ++i) {
		visited[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}

	heap->insertKey(new Node(info.source, -1, 0));
	distance[info.source] = 0;
	parent[0] = 0;

	while (!heap->isHeapEmpty()) {
		int vertice = heap->extractMinimum()->source();
		Node *it = graph->getNode(vertice);
		
        for ( ; it != NULL; it = it->next) {
            if (visited[it->destination()] == false &&
                it->distance() < distance[it->destination()]) {
            	visited[it->source()] = true;
                distance[it->destination()] = it->distance();
            	parent[it->destination()] = it->source();
				heap->insertKey(new Node(it->destination(), -1, it->distance()));
			}
		}
	}

	for (int i = 0; i < nodes; ++i) {
		LOG(distance[i]);
	}
}
