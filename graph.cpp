//alaaamer0508@gmail.com
#include "graph.hpp"
namespace graph 
{
    Graph::Graph(int vertices)
    {
        numVertices = vertices;
        adjacencyList = new Edge* [numVertices];
        for (int i = 0 ; i< numVertices ; i++)
        {
            adjacencyList[i] = nullptr;
        }
    }

    Graph::~Graph()
    {
        for(int i = 0 ; i< numVertices ; i++)
        {
            Edge* current = adjacencyList[i];
            while (current != nullptr)
            {
                Edge* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete [] adjacencyList;
    }

    void Graph::addEdge(int from, int to , int weight)
    {
        if(from < 0 || from >= numVertices || to < 0 || to >= numVertices)
        {
            throw std::invalid_argument("Invalid vertex index");
        }

        if (from == to)
        {
            std::cout << "self loop ignored: " << from << " -> " << to <<std::endl;
            return;
        }

        Edge* curr = adjacencyList[from];
        while (curr != nullptr)
        {
            if (curr->to == to)
            {
                std::cout << "Edge already exists between " << from << " -> " << to << std::endl;
                return;
            }
            curr = curr->next;
        }

        Edge* newEdge1 = new Edge (to,weight,adjacencyList[from]);
        adjacencyList[from] = newEdge1;

        Edge* newEdge2 = new Edge (from,weight,adjacencyList[to]);
        adjacencyList[to] = newEdge2;

        std::cout << "Edge added between " << from << " and " << to << " with weight " << weight << std::endl;
    }

    void Graph::removeEdge(int from, int to, int weight)
    {
        if(from < 0 || from >= numVertices || to < 0 || to >= numVertices)
        {
            throw std::invalid_argument("Invalid vertex index");
        }

        bool removed = false;

        // remove from -> to
        Edge** curr = &adjacencyList[from];
        while (curr != nullptr)
        {
            if ((*curr)->to == to)
            {
                Edge* toDelete = *curr;
                *curr = (*curr)->next;
                delete toDelete;
                removed = true;
                break;
            }
            curr = &((*curr)->next);
        }

        // remove to -> from
        Edge** curr1 = &adjacencyList[to];
        while (curr1 != nullptr)
        {
            if ((*curr1)->to == from)
            {
                Edge* toDelete = *curr1;
                *curr1 = (*curr1)->next;
                delete toDelete;
                break;
            }
            curr1 = &((*curr1)->next);
        }

        if (removed)
        {
            std::cout << "Edge removed between " << from << " and " << to << std::endl;
        }
        else{
            throw std::runtime_error("Edge does not exist between given vertices");
        }
    }

    void Graph::printGraph()
    {
        for(int i = 0 ; i < numVertices ; i++)
        {
            std::cout<< "Vertex " << i << ":";
            Edge* current = adjacencyList[i];

            while (current != nullptr)
            {
                std::cout<< " -> (to: " << current->to << ", weight: " << current->weight << ")";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    int Graph::getNumVertices() const
    {
        return numVertices;
    }

    Edge* Graph::getNeighbors(int vertices) const
    {
        if (vertices< 0 || vertices >= numVertices)
        {
            throw std::invalid_argument("Invalid vertex index");
        }
        
        return adjacencyList[vertices];
    }

    Graph Graph::fromInput(std::istream& in) {
        int numVertices, numEdges;
        std::cout << "Enter number of vertices: ";
        in >> numVertices;
        Graph g(numVertices);

        std::cout << "Enter number of edges: ";
        in >> numEdges;
        std::cout << "Enter each edge as: from to weight (0-based index):\n";
        for (int i = 0; i < numEdges; ++i) {
            int from, to, weight;
            in >> from >> to >> weight;
            g.addEdge(from, to, weight);
        }
        return g;
    }
}   
