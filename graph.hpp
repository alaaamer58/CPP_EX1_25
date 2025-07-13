//alaaamer0508@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graph.hpp"
#include <stdexcept>
#include <iostream>


namespace graph
{
    struct Edge 
    {
        int to;
        int weight;
        Edge* next;

        Edge(int t, int w, Edge* n = nullptr)
        : to(t), weight(w), next(n) {}
    };
    
    class Graph
    {
        private:
            int numVertices;
            Edge** adjacencyList;
        public:
            Graph(int vertices);
            ~Graph();


            void addEdge (int from, int to , int weight = 1);
            void removeEdge (int from, int to , int weight = 1);
            void printGraph();
            static Graph fromInput(std::istream& in);


            int getNumVertices() const;
            Edge* getNeighbors(int vertices) const;
    };
}

#endif
    