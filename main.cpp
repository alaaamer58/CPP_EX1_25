//alaaamer0508@gmail.com

#include "algorithms.hpp"
#include "graph.hpp"
#include <iostream>

using namespace std;
using namespace graph;


int main()
{
    std::cout << "=== Building sample graph ===" <<std::endl;


    Graph g(5);

    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);
    g.addEdge(3,4,9);


    std::cout << " === Original Graph ===" << std::endl;
    g.printGraph();


    std::cout << " ---- Bfs Tree from node 0 ----" << std::endl;

    Graph bfsTree = Algorithms::bfs(g,0);
    bfsTree.printGraph();


    std::cout << " ---- Dfs Tree from node 0 ----" << std::endl;

    Graph dfsTree = Algorithms::dfs(g,0);
    dfsTree.printGraph();


    std::cout << " ---- dijkstra Tree from node 0 ----" << std::endl;

    Graph dijkstraTree = Algorithms::dijkstra(g,0);
    dijkstraTree.printGraph();


    std::cout << " ---- Prim MST ----" << std::endl;

    Graph primTree = Algorithms::prim(g);
    primTree.printGraph();


    std::cout << " ---- Kruskal MST ----" << std::endl;

    Graph kruskalTree = Algorithms::kruskal(g);
    kruskalTree.printGraph();


    return 0;

}