#include "graph_coloring.h"
#include <queue>

GraphColoring::GraphColoring(Graph *graph, graph_info& info)
	: m_graph(graph)
	, m_info(info)
	, m_color(0)
	, m_availableColor(0)
	, m_visited(0)
{	
	m_color = new int [m_graph->getNodeCount()];
	m_availableColor = new bool [m_graph->getNodeCount()];
	m_visited = new bool [m_graph->getNodeCount()];
	for (int i = 0; i < m_graph->getNodeCount(); ++i) {
		m_color[i] = -1;
		m_availableColor[i] = false;
		m_visited[i] = false;
	}
}

GraphColoring::~GraphColoring()
{
	delete [] m_color;
	delete [] m_availableColor;
}

void GraphColoring::setAdjacentColors(Node *it)
{
	while (it != NULL) {
		int color = m_color[it->destination()];
		if (color != -1) {
			m_availableColor[color] = true;
		}
		it = it->next;
	}
}

void GraphColoring::resetAdjacentColors()
{
	for (int i = 0; i < m_graph->getNodeCount(); ++i) {
		m_availableColor[i] = false;
	}
}

int GraphColoring::availableColor()
{
	for (int i = 0; i < m_graph->getNodeCount(); ++i) {
		if (m_availableColor[i] == false) {
			return i;
		}
	}
}

void GraphColoring::color()
{
	int source = m_info.source;
	Node *it = m_graph->getNode(source);
	
	std::queue<Node*> queue;
	queue.push(it);
	m_color[it->source()] = 0;
	
	while (!queue.empty()) {
		it = queue.front();
		queue.pop();
		m_availableColor[it->source()] = true;
        m_visited[it->source()] = true;

		for ( ; it != NULL; it = it->next) {
			if (m_color[it->destination()] == -1 || 
				(m_color[it->source()] == m_color[it->destination()])) {
				
				if (!m_visited[it->destination()]) {
					queue.push(m_graph->getNode(it->destination()));
				}

				setAdjacentColors(m_graph->getNode(it->destination()));
				int color = availableColor();
				m_color[it->destination()] = color;	
			}
		}
		resetAdjacentColors();
	}
}

void GraphColoring::print()
{
	for (int i = 0; i < m_graph->getNodeCount(); ++i) {
		std::cout << i << "->" << getColor(m_color[i]) << std::endl;
	}
}

std::string GraphColoring::getColor(int i)
{
	switch(i) {
		case 0: return "BLUE";
				break;
		case 1: return "GREEN";
				break;
		case 2: return "RED";
				break;
		case 3: return "YELLOW";
				break;
		case 4: return "BLACK";
				break;
		case 5: return "WHITE";
				break;
		default : return "NO COLOR ASSIGNED";
				  break;
	}
}