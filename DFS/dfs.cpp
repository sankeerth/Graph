#include <stack>

#include "dfs.h"
#include "log.h"

DFS::DFS(Graph *graph, graph_info info)
	: graph(graph)
	, info(info)
	, m_visitedArray(0)
{}

DFS::~DFS()
{
	delete [] m_visitedArray;
}

void DFS::compute()
{
	int source = info.source;

	if (!graph->checkIfValidVertex(source)) {
		LOG("start vertex is not a valid one");
		return;
	}

	m_visitedArray = new bool [graph->getNodeCount()+1];
	for(int i = 0; i <= graph->getNodeCount(); ++i) {
		m_visitedArray[i] = false;
	}

	std::stack<int> stack;
	stack.push(source);

	while (!stack.empty()) {
		int currentVertex = stack.top();
		LOG(currentVertex);
		m_visitedArray[currentVertex] = true;
		stack.pop();

		Node *it = graph->getNode(currentVertex);
		while (it != NULL) {
			int vertex = it->destination();
			if (!m_visitedArray[vertex]) {
				stack.push(vertex);
				m_visitedArray[vertex] = true;
			}
			it = it->next;
		}
	}
}
