#include <queue>

#include "bfs.h"
#include "log.h"

BFS::BFS(Graph *g, graph_info info)
	: graph(g)
	, info(info)
	, m_visitedArray(0)
{}

BFS::~BFS()
{
	delete [] m_visitedArray;
}

void BFS::compute()
{
	int source = info.source;

	if (!graph->checkIfValidVertex(source)) {
		LOG("start vertex is not a valid one");
		return;
	}

	m_visitedArray = new bool [graph->getNodeCount()];
	for(int i = 0; i < graph->getNodeCount(); ++i) {
		m_visitedArray[i] = false;
	}

	std::queue<int> queue;
	queue.push(source);

	while(!queue.empty()) {
		int currentVertex = queue.front();
		LOG(currentVertex);
		m_visitedArray[currentVertex] = true;
		queue.pop();

		Node *it = graph->getNode(currentVertex);
		while (it != NULL) {
			int vertex = it->destination();
			if (!m_visitedArray[vertex]) {
				queue.push(vertex);
				m_visitedArray[vertex] = true;
			}
			it = it->next;
		}
	}
}

