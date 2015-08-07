#ifndef PRIM_MST_H
#define PRIM_MST_H

#include "Graph.h"

class PrimMST
{
  public:
	static PrimMST* create(Graph *graph, graph_info& info)
	{
		return new PrimMST(graph, info);
	}

	void compute();
	~PrimMST();
  private:
	PrimMST(Graph *graph, graph_info info);

	Graph *graph;
	graph_info info;
	int *distance;
	bool *visited;
	int *parent;	
};

#endif