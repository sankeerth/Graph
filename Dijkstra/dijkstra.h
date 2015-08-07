#ifndef DIJSKTRA_H
#define DIJSKTRA_H

#include "Graph.h"

class dijkstra
{
  public:
	static dijkstra* create(Graph *graph, graph_info& info)
	{
		return new dijkstra(graph, info);
	}

	void compute();
	~dijkstra();
  private:
	dijkstra(Graph *graph, graph_info info);

	Graph *graph;
	graph_info info;
	int *distance;
	bool *visited;
};

#endif