#include "Graph.h"
#include "log.h"

Graph::Graph()
{
	LOG("Graph created");
}

Graph::~Graph()
{
	LOG("Graph destroyed");
	for (int i = 0; i < m_numOfNodes; ++i) {
		Node *prevNode = nodeList[i].head;
		Node *nextNode = nodeList[i].head;
		while (prevNode != NULL) {
			nextNode = nextNode->next;
			delete prevNode;
			prevNode = NULL;
			prevNode = nextNode;
		}
	}

	delete [] nodeList;
}

Graph* Graph::create(int nodes)
{
	if (nodes <= 0) {
		LOG("create graph with nodes greater that 0");
		return NULL;
	}

	Graph *graph  =  new Graph();
	if (graph == NULL) {
		LOG("creation of graph failed. Return");
		return NULL;
	}

	graph->m_numOfNodes = nodes;
	graph->nodeList = new list [nodes];

	for (int i = 0; i < nodes; ++i) {
		graph->nodeList[i].head = NULL;
	}

	return graph;
}

bool Graph::checkIfValidVertex(int vertex)
{
	if (vertex < 0 || vertex > m_numOfNodes) {
		return false;
	}
	return true;
}

int Graph::getNodeCount()
{
	return m_numOfNodes;
}

void Graph::addEdge(int fromVertice, int toVertice, int distance)
{
	if (!checkIfValidVertex(fromVertice)) {
		LOG("Enter a valid from vertice");
        return;
	}

	if (!checkIfValidVertex(toVertice)) {
		LOG("Enter a valid to vertice");
        return;
	}

	Node* node = createNode(fromVertice, toVertice, distance);
	node->next = nodeList[fromVertice].head;
	nodeList[fromVertice].head = node;

	node =  createNode(toVertice, fromVertice, distance);
	node->next = nodeList[toVertice].head;
	nodeList[toVertice].head = node;
}

void Graph::addDirectedEdge(int fromVertice, int toVertice, int distance)
{
	if (!checkIfValidVertex(fromVertice)) {
		LOG("Enter a valid from vertice");
        return;
	}

	if (!checkIfValidVertex(toVertice)) {
		LOG("Enter a valid to vertice");
        return;
	}

	Node* node = createNode(fromVertice, toVertice, distance);
	node->next = nodeList[fromVertice].head;
	nodeList[fromVertice].head = node;
}

Node* Graph::createNode(int from, int to, int distance)
{
	return new Node(from, to, distance);
}

Node* Graph::getNode(int vertex)
{
	return nodeList[vertex].head;
}
