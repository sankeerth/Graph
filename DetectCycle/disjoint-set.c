#include "Graph.h"
#include "log.h"

int find(int *parent, int vertice);
void Union(int *parent, int source, int dest);

bool isCyclicUsingDisjointSet(Graph *graph, graph_info& info)
{
	int nodes = graph->getNodeCount();
	int *parent = new int [nodes];

	for (int i = 0; i < nodes; ++i) {
		parent[i] = -1;
	}

	for (int i = 0; i < nodes; ++i) {
		Node *it = graph->getNode(i);
		for ( ; it != NULL; it = it->next) {
			int x = find(parent, it->source());
			int y = find(parent, it->destination());

			if (x == y) {
				return true;
			}

			Union(parent, x, y);
		}
	}
}

int find(int *parent, int vertice)
{
	if (parent[vertice] == -1) {
		return vertice;
	}
	return find(parent, parent[vertice]);
}

void Union(int *parent, int source, int dest)
{
	int xset = find(parent, source);
	int yset = find(parent, dest);
	parent[xset] = yset;
}
