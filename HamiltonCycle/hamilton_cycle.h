#ifndef HAMILTON_CYCLE_H
#define HAMILTON_CYCLE_H

#include "Graph.h"
#include <vector>

class HamiltonCycle
{
  public:
    static HamiltonCycle* create(Graph *graph, graph_info& info)
    {
    	return new HamiltonCycle(graph, info);
    }
    ~HamiltonCycle();
    void checkHamiltonCycle();
  private:
    HamiltonCycle(Graph *graph, graph_info& info);
    bool isHamiltonCycle(int vertex);
    bool isCompleteGraphVisited();
    void visitIncrease();
    void visitDecrease();
    void print();

    Graph *m_graph;
    graph_info m_info;
    bool *m_visited;
    int m_visitedCount;
    std::vector<int> m_vector;
};

#endif