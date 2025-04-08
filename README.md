//alaaamer0508@gmail.com
# Graph Algorithms Project

## 🎯 About the Project

This project implements a graph data structure in C++ and provides classic graph algorithms:

- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Dijkstra's Algorithm
- Prim's Algorithm (Minimum Spanning Tree)
- Kruskal's Algorithm (Minimum Spanning Tree)

Each algorithm returns a new graph that represents the result (BFS tree, DFS tree, shortest paths tree, or MST).

---

## 🧱 Project Structure

### ➤ Graph Representation

- `Graph.hpp` / `Graph.cpp`  
  Contains the `Graph` class and `Edge` struct.  
  The graph is represented using an **adjacency list** with linked lists.

- `Queue.hpp` / `Queue.cpp`  
  A basic FIFO queue implemented using a circular array. Used by BFS.

- `UnionFind.hpp` / `UnionFind.cpp`  
  Implements Union-Find (Disjoint Set Union) used in Kruskal’s algorithm.

---

### ➤ Algorithms

- `Algorithms.hpp` / `Algorithms.cpp`  
  A static class that implements:
  - `bfs(const Graph& g, int start)`
  - `dfs(const Graph& g, int start)`
  - `dijkstra(const Graph& g, int start)`
  - `prim(const Graph& g)`
  - `kruskal(const Graph& g)`

Each function builds and returns a new `Graph` with the relevant edges.
