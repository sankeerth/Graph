#include "dijkstra.h"
#include "Graph.h"
#include "log.h"
#include "../HEAP/HeapFactory.h"
#include <iostream>
#include <limits.h>

dijkstra::dijkstra(Graph *graph, graph_info info)
	: graph(graph)
	, info(info)
	, distance(0)
	, visited(0)
{}

dijkstra::~dijkstra()
{
	delete [] distance;
	delete [] visited;
}

void dijkstra::compute()
{
	int nodes = graph->getNodeCount();

	distance = new int [nodes];
	visited = new bool [nodes];

	HeapType type = Min;
	Heap<Node*> *heap = HeapFactory::create<Node*>(type);

	for (int i = 0; i < nodes; ++i) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[info.source] = 0;
	heap->insertKey(new Node(info.source, -1, 0));

	while (!heap->isHeapEmpty()) {
		int vertice = heap->extractMinimum()->source();
		Node *it = graph->getNode(vertice);

		for ( ; it != NULL; it = it->next) {
			if (!visited[it->destination()] &&
				(distance[it->destination()] > it->distance() + distance[it->source()])) {
				visited[it->source()] = true;
				distance[it->destination()] = it->distance() + distance[it->source()];
				heap->insertKey(new Node(it->destination(), -1, distance[it->destination()]));
			}
		}
	}

	for (int i = 0; i < nodes; ++i) {
		LOG(distance[i]);
	}
}