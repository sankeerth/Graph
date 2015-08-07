#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "Graph.h"
#include <stack>

class TopologicalSort
{
  public:
  	static TopologicalSort* create(Graph *graph, graph_info& info)
  	{
  		return new TopologicalSort(graph, info);
  	}
  	~TopologicalSort();
  	void sort();
  	void print();
  private:
  	TopologicalSort(Graph *graph, graph_info& info);
  	void sortUtil(int vertice, bool *visited);
  	Graph *m_graph;
  	graph_info m_info;
  	std::stack<int> m_stack;
};

#endif