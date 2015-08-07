#include "GraphUtilities.h"
#include "log.h"

int main()
{
	Graph *graph = Graph::create(9);

	graph_info info;
    info.source = 0;
    info.destination = 0;

    graph->addEdge(0, 1, 4);
    graph->addEdge(0, 7, 8);
    graph->addEdge(1, 2, 8);
    graph->addEdge(1, 7, 11);
    graph->addEdge(2, 3, 7);
    graph->addEdge(2, 8, 2);
    graph->addEdge(2, 5, 4);
    graph->addEdge(3, 4, 9);
    graph->addEdge(3, 5, 14);
    graph->addEdge(4, 5, 10);
    graph->addEdge(5, 6, 2);
    graph->addEdge(6, 7, 1);
    graph->addEdge(6, 8, 6);
    graph->addEdge(7, 8, 7);

    // DFS
    LOG("======== DFS start========");
    DFS *dfs = DFS::create(graph, info);
    dfs->compute();
    delete(dfs);
    LOG("======== DFS end========");

    // BFS
    LOG("======== BFS start========");
    BFS *bfs = BFS::create(graph, info);
    bfs->compute();
    delete(bfs);
    LOG("======== BFS end========");

    // dijkstra
    LOG("======== dijkstra start========");
    dijkstra *dijkstra = dijkstra::create(graph, info);
    dijkstra->compute();
    delete(bfs);
    LOG("======== dijkstra end========");

    // PrimMST
    LOG("======== PrimMST start========");
    PrimMST *prim = PrimMST::create(graph, info);
    prim->compute();
    delete(prim);
    LOG("======== PrimMST end========");

    // BellmanFord
    LOG("======== BellmanFord start========");
    BellmanFord *bellman_ford = BellmanFord::create(graph, info);
    bellman_ford->compute();
    delete(bellman_ford);
    LOG("======== BellmanFord end========");

    // ShortestPath
    LOG("======== ShortestPath start========");
    ShortestPath *shortest_path = ShortestPath::create(graph, info);
    shortest_path->compute();
    delete(shortest_path);
    LOG("======== ShortestPath end========");

    // Detect Cycle
    LOG("======== Detect Cycle start========");
    isCyclic(graph, info);
    LOG("======== Detect Cycle end========");

    // Detect Cycle using Disjoint set
    LOG("======== Detect Cycle using Disjoint set start========");
    LOG(isCyclicUsingDisjointSet(graph, info));
    LOG("======== Detect Cycle using Disjoint set end========");

    // Graph Coloring
    LOG("======== Graph Coloring start========");
    GraphColoring *graph_color = GraphColoring::create(graph, info);
    graph_color->color();
    graph_color->print();
    LOG("======== Graph Coloring end========");

    // Hamilton Cycle
    LOG("======== Hamilton Cycle start========");
    HamiltonCycle *hamiton = HamiltonCycle::create(graph, info);
    hamiton->checkHamiltonCycle();
    LOG("======== Hamilton Cycle end========");

    delete graph;

    // Directed Graph
    graph = Graph::create(6);

    graph->addDirectedEdge(0, 1);
    graph->addDirectedEdge(0, 5);
    graph->addDirectedEdge(1, 2);
    graph->addDirectedEdge(1, 3);
    graph->addDirectedEdge(1, 4);
    graph->addDirectedEdge(2, 3);
    graph->addDirectedEdge(2, 4);
    graph->addDirectedEdge(3, 4);
    graph->addDirectedEdge(5, 2);

    LOG("======== Topological Sort start========");
    TopologicalSort *tsort = TopologicalSort::create(graph, info);
    tsort->sort();
    tsort->print();
    LOG("======== Topological Sort end========");

	return 0;
}
