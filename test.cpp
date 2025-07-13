#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "graph.hpp"
#include "algorithms.hpp"
#include <sstream>

using namespace graph;

TEST_CASE("BFS on simple graph") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph bfsTree = Algorithms::bfs(g, 0);
    CHECK(bfsTree.getNumVertices() == 4);
}

TEST_CASE("DFS on simple graph") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK(dfsTree.getNumVertices() == 4);
}

TEST_CASE("Kruskal MST") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 2);

    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.getNumVertices() == 5);
}

TEST_CASE("Prim MST") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 4);

    Graph mst = Algorithms::prim(g);
    CHECK(mst.getNumVertices() == 5);
}

TEST_CASE("Dijkstra shortest path") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 4);

    Graph shortest = Algorithms::dijkstra(g, 0);
    CHECK(shortest.getNumVertices() == 4);
}
