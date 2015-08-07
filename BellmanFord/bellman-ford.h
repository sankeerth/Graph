#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "Graph.h"

class BellmanFord
{
  public:
  	static BellmanFord* create(Graph *graph, graph_info info)
  	{
  		return new BellmanFord(graph, info);
  	}
    ~BellmanFord();
    void compute();
  private:
  	BellmanFord(Graph *graph, graph_info info);

  	Graph *graph;
  	graph_info info;
  	int *distance;
  	bool *visited;
};

#endif