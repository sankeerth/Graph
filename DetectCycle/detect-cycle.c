#include "Graph.h"
#include "log.h"
#include <vector>

std::vector<int> vect;
bool isCyclicUtil(Graph *graph, bool *visited, bool *recr, int vertex);
void printNodes(std::vector<int> vect);

bool isCyclic(Graph *graph, graph_info& info)
{
	int nodes = graph->getNodeCount();
	bool *visited = new bool [nodes];
	bool *recr = new bool[nodes];

	for (int i = 0; i < nodes; ++i) {
		visited[i] = false;
		recr[i] = false;
	}

		recr[info.source] = true;
		vect.push_back(info.source);
		if (isCyclicUtil(graph, visited, recr, info.source)) {
			LOG("Cycle detected");
			printNodes(vect);
			LOG(info.source);
			vect.clear();	
			return true;
		} else {
			vect.clear();
			return false;
		}
}

bool isCyclicUtil(Graph *graph, bool *visited, bool *recr, int vertex)
{
	Node *it = graph->getNode(vertex);
	visited[vertex] = true;

	for ( ; it != NULL; it = it->next) {
		if (recr[it->destination()]) {
			return true;
		}
		if (!(visited[it->destination()])) {
			vect.push_back(it->destination());
			return isCyclicUtil(graph, visited, recr, it->destination());
		}
	}
	return false;
}

void printNodes(std::vector<int> vect)
{
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it) {
		LOG(*it);
	}
}