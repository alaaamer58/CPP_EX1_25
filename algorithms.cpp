//alaaamer0508@gmail.com

#include "algorithms.hpp"
#include "queue.hpp"
#include "unionFind.hpp"
#include "stdexcept"
#include "limits.h"

namespace graph
{

    struct EdgeData
    {
        int from;
        int to;
        int weight;
    };

    Graph Algorithms::bfs(const Graph& g , int start)
    {
        int n = g.getNumVertices();
        if (start < 0 || start >= n)
        {
            throw std::invalid_argument("Invalid  start vertex");
        }

        Graph bfsTree(n);
        bool* visited = new bool[n]();
        Queue q(n);
        
        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty())
        {
            int current = q.dequeue();
            Edge* neighbors = g.getNeighbors(current);

            while (neighbors != nullptr)
            {
                int neighbor = neighbors->to;
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    bfsTree.addEdge(current,neighbor,neighbors->weight);
                    q.enqueue(neighbor);
                }
                neighbors = neighbors->next;
            }
            
        }
        
        delete [] visited;
        return bfsTree;
    }


    void dfsVisit(const Graph& g , int current , bool* visited, Graph& tree)
    {
        visited[current] = true;

        Edge* neighbors = g.getNeighbors(current);
        while(neighbors != nullptr)
        {
            int neighbor = neighbors->to;
            if (!visited[neighbor])
            {
                tree.addEdge(current , neighbor, neighbors->to);
                dfsVisit(g, neighbor, visited, tree);
            }
            neighbors = neighbors->next;
        }
    }


    Graph Algorithms::dfs(const Graph& g , int start)
    {
        int n = g.getNumVertices();
        if (start < 0 || start >= n)
        {
            throw std::invalid_argument("Invalid  start vertex");
        }

        Graph dfsTree(n);
        bool* visited = new bool[n]();

        dfsVisit(g , start, visited , dfsTree);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfsVisit(g , i , visited , dfsTree);
            }
        }
        
        delete[] visited;
        return dfsTree;
    }


    Graph Algorithms::dijkstra(const Graph& g , int start)
    {
        int n = g.getNumVertices();
        if (start < 0 || start >= n)
        {
            throw std::invalid_argument("Invalid  start vertex");
        }

        Graph dijkstraTree(n);
        int* distance = new int[n];
        bool* visited = new bool[n]();
        int* parent = new int[n];

        for(int i = 0; i < n; i++)
        {
            distance[i] = INT_MAX;
            parent[i] = -1;
        }
        distance[start] = 0; 

        for (int i = 0; i < n; i++)
        {
            int minDist = INT_MAX;
            int u = -1;
            for(int j = 0 ; j < n ; j++)
            {
                if (!visited[j] && distance[j] < minDist)
                {
                    minDist = distance [j];
                    u=j;
                }
            }

            if (u == -1)
            {
                break;
            }
            
            visited[u] = true;
            Edge* neighbors = g.getNeighbors(u);
            while (neighbors != nullptr)
            {
                int v = neighbors->to;
                int weight = neighbors->weight;
                if (!visited[v] && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    parent[v] = u ;
                }
                neighbors = neighbors->next;
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            if (parent[i] != -1)
            {
                int u =parent[i];
                int v = i;
                Edge* neighbors = g.getNeighbors(u);
                while (neighbors != nullptr)
                {
                    if (neighbors->to == v)
                    {
                        dijkstraTree.addEdge(u,v,neighbors->weight);
                        break;
                    }
                    neighbors = neighbors->next;
                }
                
            }
            
        }

        delete[] distance;
        delete[] visited;
        delete[] parent;
        return dijkstraTree;
    }

    Graph Algorithms::prim(const Graph& g)
    {
        int n = g.getNumVertices();
        Graph mst(n);
        bool* inMst = new bool[n]();
        int* minWeight = new int[n];
        int* parent = new int[n];


        for (int i = 0; i < n; i++)
        {
            minWeight[i] = INT_MAX;
            parent[i] = -1;
        }

        minWeight[0] = 0;

        for(int i = 0; i< n ; i++)
        {
            int u = -1;
            int min = INT_MAX;

            for (int j = 0; j < n; j++)
            {
                if (!inMst[j] && minWeight[j] < min)
                {
                    min = minWeight[j];
                    u = j;
                }
            }
            
            if(u == -1)
            {
                break;
            }

            inMst[u] = true;

            Edge* neighbors = g.getNeighbors(u);

            while (neighbors != nullptr)
            {
                int v = neighbors->to;
                int weight = neighbors->weight;
                if (!inMst[v] && weight <minWeight[v])
                {
                    minWeight[v] = weight;
                    parent[v] = u;
                }
                neighbors = neighbors->next;
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            if (parent[i] != -1)
            {
                Edge* neighbors = g.getNeighbors(i);
                while (neighbors != nullptr)
                {
                    if (neighbors->to == parent[i])
                    {
                        mst.addEdge(i , parent[i] ,neighbors->weight);
                        break;
                    }
                    neighbors = neighbors->next;
                }
            }
            
        }
        
        delete[] parent;
        delete[] inMst;
        delete[] minWeight;

        return mst;
    }


    Graph Algorithms::kruskal(const Graph& g)
    {
        int n = g.getNumVertices();
        Graph mst(n);
        UnionFind uf(n);


        int maxEdges = n * (n-1) / 2;
        EdgeData* edges = new EdgeData[maxEdges];
        int edgeCount = 0;

        for(int i = 0 ; i< n ; i++)
        {
            Edge* curr = g.getNeighbors(i);
            while (curr != nullptr)
            {
                if (i< curr->to)
                {
                    edges[edgeCount++] = {i, curr->to , curr->weight};
                }
                curr = curr->next;
            }
            
        }

        for(int i = 0 ; i <edgeCount -1 ; i++)
        {
            int minIndex = i;
            for(int j = i+1 ; j < edgeCount ; j++)
            {
                if(edges[j].weight < edges[minIndex].weight)
                {
                    minIndex = j;
                }
            }
            if(minIndex != i)
            {
                EdgeData temp = edges[i];
                edges[i] = edges[minIndex];
                edges[minIndex] = temp;
            }
        }

        for (int i = 0; i < edgeCount; i++)
        {
            int u = edges[i].from;
            int v = edges[i].to;
            if (!uf.connected(u,v))
            {
                uf.unite(u,v);
                mst.addEdge(u,v, edges[i].weight);
            }
        }

        delete[] edges;
        return mst;
        
    }


}