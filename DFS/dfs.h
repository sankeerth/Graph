#ifndef DFS_H
#define DFS_H

#include "Graph.h"

class DFS
{
  public:
  	static DFS* create(Graph *graph, graph_info info)
  	{
  		return new DFS(graph, info);
  	}

	~DFS();
	void compute();
  private:
	DFS(Graph *graph, graph_info info);

  	Graph *graph;
  	graph_info info;	
  	bool *m_visitedArray;
};

#endif