#ifndef GRAPH_H
#define GRAPH_H

typedef struct GraphInfo
{
  int source;
  int destination;
}graph_info;

class Node;

struct list
{
	Node *head;	
};

class Graph {
public:
	~Graph();
	static Graph* create(int vertices);
	bool checkIfValidVertex(int vertex);
	int getNodeCount();
	void addEdge(int fromVertice, int toVertice, int distance = 0);
	void addDirectedEdge(int fromVertice, int toVertice, int distance = 0);
	Node* getNode(int vertex);
private:
	Graph();
    Node* createNode(int from, int to, int distance = 0);
	list* nodeList;
	int m_sourceVertex;
	int m_numOfNodes;
};

class Node {
  public:
  	Node() {}
  	Node(int source, int dest, int distance = 0)
  	: m_source(source)
  	, m_dest(dest)
  	, m_distance(distance)
  	{}
  	bool operator > (Node* n)
  	{
  		return m_distance > n->distance();
  	}

  	bool operator < (Node* n)
  	{
  		return m_distance < n->distance();
  	}

  	Node* operator = (int x)
  	{
  		m_distance = x;
  		return this;
  	}
/*
  	bool operator > (int x)
  	{
  		return m_distance > x;
  	}

  	bool operator < (int x)
  	{
  		return m_distance < x;
  	}
*/
  	int source() {return m_source; }
  	int destination() {return m_dest; }
  	int distance() {return m_distance; }
  	void set(int x) { m_distance = x; }
	
	Node *next;
  private:
  	int m_source;
  	int m_dest;
  	int m_distance;
};

#endif
