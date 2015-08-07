#include "hamilton_cycle.h"
#include "log.h"

HamiltonCycle::HamiltonCycle(Graph *graph, graph_info& info)
	: m_graph(graph)
	, m_info(info)
	, m_visited(0)
	, m_visitedCount(0)
	, m_vector(0)
{
	m_visited = new bool [m_graph->getNodeCount()];
	for (int i = 0; i < m_graph->getNodeCount(); ++i) {
		m_visited[i] = false;
	}
}

HamiltonCycle::~HamiltonCycle()
{
	delete [] m_visited;
}

bool HamiltonCycle::isCompleteGraphVisited()
{
	return (m_visitedCount == m_graph->getNodeCount());
}

void HamiltonCycle::visitIncrease()
{
	m_visitedCount++;
}

void HamiltonCycle::visitDecrease()
{
	m_visitedCount--;
}

void HamiltonCycle::checkHamiltonCycle()
{
	Node *start = m_graph->getNode(m_info.source);
	m_vector.push_back(m_info.source);
	m_visited[m_info.source] = true;
	visitIncrease();
	if (start != NULL) {
		if (isHamiltonCycle(start->destination())) {
			LOG("HamiltonCycle present!!");
			m_vector.push_back(m_info.source);
			print();
		} else {
			LOG("No HamiltonCycle");
		}
	}
}

bool HamiltonCycle::isHamiltonCycle(int vertex)
{
	if (isCompleteGraphVisited()) {
		return true;
	}
	m_visited[vertex] = true;
	m_vector.push_back(vertex);

	for (Node *it = m_graph->getNode(vertex); it != NULL; it = it->next) {
		if (m_visited[it->destination()] == false) {
			visitIncrease();
			if (isHamiltonCycle(it->destination())) {
				return true;
			}
        } else {
            continue;
        }
        // is this required?
		m_vector.pop_back();
		visitDecrease();
		m_visited[it->destination()] = false;
	}
	return false;
}

void HamiltonCycle::print()
{
	for (std::vector<int>::iterator it = m_vector.begin(); it != m_vector.end(); ++it) {
		LOG(*it);
	}
}
