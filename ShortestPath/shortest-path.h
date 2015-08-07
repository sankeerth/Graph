#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "Graph.h"

class ShortestPath
{
  public:
    static ShortestPath* create(Graph *graph, graph_info info)
    {
    	return new ShortestPath(graph, info);
    }
    ~ShortestPath();
    void compute();
  private:
  	ShortestPath(Graph *graph, graph_info info);

  	Graph *graph;
  	graph_info info;
  	int *distance;
	  bool *visited;
};

#endif