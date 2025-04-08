//alaaamer0508@gmail.com

#include "unionFind.hpp"

namespace graph
{
    UnionFind::UnionFind(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    UnionFind::~UnionFind()
    {
        delete[] parent;
        delete[] rank;
    }

    int UnionFind::find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void UnionFind::unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
        {
            return;
        }
        else if(rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool UnionFind::connected(int x , int y)
    {
        return find(x) == find(y) ;
    }
}