#include "bellman-ford.h"
#include "log.h"
#include <iostream>
#include <queue>
#include <limits.h>

BellmanFord::BellmanFord(Graph *graph, graph_info info)
	: graph(graph)
	, info(info)
	, distance(0)
	, visited(0)
{}

BellmanFord::~BellmanFord()
{
	delete [] distance;
	delete [] visited;
}

void BellmanFord::compute()
{
	int nodes = graph->getNodeCount();
	distance = new int [nodes];
	visited = new bool [nodes];

	for (int i = 0; i < nodes; ++i) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[info.source] = 0;
	visited[info.source] = true;

	std::queue<int> queue;

	for (int j = 0; j < nodes-1; ++j) {
		queue.push(info.source);
		
		while(!queue.empty()) {
			Node *it = graph->getNode(queue.front());

			while (it != NULL) {
				if (!visited[it->destination()]) {
					queue.push(it->destination());
					visited[it->destination()] = true;
				}

				if ((distance[it->destination()] == INT_MAX) || 
						(distance[it->destination()] > distance[it->source()] + it->distance())) {
					distance[it->destination()] = it->distance() + distance[it->source()];
				}
				it = it->next;
			}
			queue.pop();
		}

		for (int i = 0; i < nodes; ++i) {
			visited[i] = false;
		}
	}


	// Check negative weight cycle
	if (!queue.empty()) {
		LOG("queue is not empty, PROBLEM!!");
	}

	queue.push(info.source);
	for (int i = 0; i < nodes; ++i) {
		visited[i] = false;
	}
	visited[info.source] = true;
	
	while (!queue.empty()) {
		Node *it = graph->getNode(queue.front());
		while (it != NULL) {
			if (!visited[it->destination()]) {
				queue.push(it->destination());
				visited[it->destination()] = true;
			}

			if (distance[it->destination()] > distance[it->source()] + it->distance()) {
				LOG("Negative weight cycle !!");
			}
			it = it->next;
		}
		queue.pop();
	}
	// negative weight cycle

	// Print the distance array
	for (int i = 0; i < nodes; ++i) {
		LOG(distance[i]);
	}
}
