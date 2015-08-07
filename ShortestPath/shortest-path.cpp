#include "shortest-path.h"
#include "Graph.h"
#include "log.h"
#include <iostream>
#include <limits.h>
#include <queue>

ShortestPath::ShortestPath(Graph *graph, graph_info info)
	: graph(graph)
	, info(info)
	, distance(0)
	, visited(0)
{}

ShortestPath::~ShortestPath()
{
	delete [] distance;
	delete [] visited;
}

void ShortestPath::compute()
{
	int nodes = graph->getNodeCount();
	distance = new int [nodes];
	visited = new bool [nodes];

	for (int i = 0; i < nodes; ++i) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	
    visited[info.source] = true;
	distance[info.source] = 0;

	std::queue<int> queue;
    int nextNode = info.source;
    queue.push(nextNode);

	while (!queue.empty()) {
        Node* it = graph->getNode(nextNode);
        while ( it != NULL) {
			int source = it->source();
			int dest = it->destination();
			
			if (!visited[dest]) {
				queue.push(dest);
                visited[dest] = true;
			}

			if ((distance[dest] == INT_MAX) || 
					(distance[dest] > distance[source] + it->distance())) {
				distance[dest] = it->distance() + distance[source];
			}

            it = it->next;
		}
        queue.pop();
        nextNode = queue.front();
	}

	for (int i = 0; i < nodes; ++i) {
		LOG(distance[i]);
	}
}