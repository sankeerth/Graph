#ifndef BFS_H
#define BFS_H

#include "Graph.h"

class BFS
{
  public:
  	static BFS* create(Graph *graph, graph_info info)
  	{
  		return new BFS(graph, info);
  	}

  	~BFS();
  	void compute();
  private:
  	BFS(Graph *graph, graph_info info);

  	Graph *graph;
  	graph_info info;	
  	bool *m_visitedArray;
};

#endif