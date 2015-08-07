#ifndef GRAPH_COLORING_H
#define GRAPH_COLORING_H

#include "Graph.h"
#include "log.h"

class GraphColoring
{
  public:
    static GraphColoring* create(Graph *graph, graph_info& info)
    {
    	return new GraphColoring(graph, info);
    }
    void color();
    void print();
    ~GraphColoring();
  private:
  	GraphColoring(Graph *graph, graph_info& info);
  	void setAdjacentColors(Node *it);
  	void resetAdjacentColors();
  	int availableColor();
  	std::string getColor(int i);

  	Graph *m_graph;
  	graph_info m_info;
  	int *m_color;
  	bool *m_availableColor;
  	bool *m_visited;
};

#endif