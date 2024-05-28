/*
211691159
elifrydman08@gmail.com
*/

#include "Graph.hpp"
using namespace std;

namespace ariel
{

    void Graph::loadGraph(const std::vector<std::vector<int>> &graph)
    {

        // Check if the graph is a square matrix.

        for (size_t i = 0; i < graph.size(); i++)
        {
            if (graph[i].size() != graph.size())
            {
                throw invalid_argument(" Invalid_argument-The graph is not a square matrix.");
            }
        }

        // Check if the graph is empty.
        if (graph.empty())
        {
            throw invalid_argument(" Invalid_argument-The graph is empty.");
        }

        // Check if the graph has a self loop
        for (size_t i = 0; i < graph.size(); i++)
        {
            if (graph[i][i] != 0)
            {
                throw invalid_argument(" Invalid_argument-The graph has a self loop.");
            }
        }

        adjMatrix = graph;
    }

    void Graph::printGraph()
    {
        size_t numVertices = adjMatrix.size();

        for (size_t i = 0; i < numVertices; i++)
        {
            for (size_t j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    /*
    this function check if the graph is connected
    */
    auto Graph::isWeightedGraph() -> bool
    {

        size_t size = adjMatrix.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (adjMatrix[i][j] != 1 && adjMatrix[i][j] != 0)
                {

                    return true;
                }
            }
        }

        return false;
    }

    /*
    this function check if the graph is directed
    if the graph is syimetric the graph is not directed -false
    if the graph is  not syimetric the graph is directed - true
    */
    auto Graph::isDirectedGraph() -> bool
    {
        size_t size = adjMatrix.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (adjMatrix[i][j] != adjMatrix[j][i])
                {
                    return true;
                }
            }
        }

        return false;
    }

    auto Graph::getNumberOfEdges() -> size_t
    {
        size_t size = adjMatrix.size();
        int numEdges = 0;

        if (isDirectedGraph())
        { // if the graph is directed
            for (size_t i = 0; i < size; i++)
            {
                for (size_t j = 0; j < size; j++)
                {
                    if (adjMatrix[i][j] != 0)
                    {
                        numEdges++;
                    }
                }
            }
            return static_cast<size_t>(numEdges);
        }
        // undirected graph
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i; j < size; j++)
            {
                if (adjMatrix[i][j] != 0)
                {
                    numEdges++;
                }
            }
        }
        return (size_t)numEdges;
    }
    auto Graph::getNeighbors(size_t vertex) -> std::vector<int>
    {
        std::vector<int> neighbors;
        size_t size = adjMatrix.size();

        for (size_t i = 0; i < size; i++)
        {
            if (adjMatrix[vertex][i] != 0)
            {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }

    // get the size of the graph
    auto Graph::getSize() const-> size_t
    {
        return adjMatrix.size();
    }

    /*
    this function check if the graph has negative weight
    */
    auto Graph::isNegativeWeightedGraph() -> bool
    {
        size_t size = adjMatrix.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (adjMatrix[i][j] < 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // getWeight

    auto Graph::getWeight(size_t src, size_t dest) -> int
    {
        return adjMatrix[src][dest];
    }

    auto Graph::getNumberOfVertices() -> size_t
    {
        return adjMatrix.size();
    }

    //////////////////////////       EX 2      /////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    //Graph::Graph() {} // Add a default constructor to the Graph class





    //////////////////////////// // Aritmetic operators /////////////////////////////////
    Graph Graph::operator+(Graph &other)
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            throw invalid_argument(" Invalid_argument-The graphs are not the same size.");
        }

        std::vector<std::vector<int>> newGraph(g1hSize, std::vector<int>(g1hSize, 0));
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                newGraph[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
            }
        }
        Graph g;
        g.loadGraph(newGraph);
        return g;
    }

    Graph Graph::operator+=(Graph &other)
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            throw invalid_argument(" Invalid_argument-The graphs are not the same size.");
        }

        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
        
            {
                adjMatrix[i][j] += other.adjMatrix[i][j];
            
            }
        }
        return *this;
    }

    Graph Graph::operator+()
    {
        return *this;
    }

    Graph Graph::operator-(Graph &other)
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            throw invalid_argument(" Invalid_argument-The graphs are not the same size.");
        }

        std::vector<std::vector<int>> newGraph(g1hSize, std::vector<int>(g1hSize, 0));
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                newGraph[i][j] = adjMatrix[i][j] - other.adjMatrix[i][j];
            }
        }
        Graph g;
        g.loadGraph(newGraph);
        return g;
    }

    Graph Graph::operator-=(Graph &other)
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            throw invalid_argument(" Invalid_argument-The graphs are not the same size.");
        }

        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j] -= other.adjMatrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator-()
    {
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j] = -adjMatrix[i][j];
            }
        }
        return *this;
    }


////////////// comperators //////////////////////

    bool Graph::operator==(const Graph &other) const
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            return false;
        }

        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (adjMatrix[i][j] != other.adjMatrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Graph::operator!=(const Graph &other) const
    {
        return !(*this == other);
    }

    bool Graph::operator<(const Graph &other) const
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            throw invalid_argument(" Invalid_argument-The graphs are not the same size.");
        }

        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (adjMatrix[i][j] >= other.adjMatrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Graph::operator<=(const Graph &other) const
    {
        return *this < other || *this == other;
    }

    bool Graph::operator>(const Graph &other) const
    {
        return !(*this <= other);
    }

    bool Graph::operator>=(const Graph &other) const
    {
        return !(*this < other);
    }

    




//////prefix and postfix //////////////

    Graph Graph::operator++() // prefix increment ++i
    {
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j]++;
            }
        }
        return *this;
    }

    Graph Graph::operator++(int) // postfix increment i++
    {
        Graph temp = *this;
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j]++;
            }
        }
        return temp;
    }

    Graph Graph::operator--() // prefix decrement --i
    {
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j]--;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) // postfix decrement i--
    {
        Graph temp = *this;
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j]--;
            }
        }
        return temp;
    }

///////// multiplication /////////////////////

    Graph Graph::operator*(Graph &other) // Multiply the two graphs together.
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            throw invalid_argument(" Invalid_argument-The graphs are not the same size.");
        }

        std::vector<std::vector<int>> newGraph(g1hSize, std::vector<int>(g1hSize, 0));
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                for (size_t k = 0; k < size; k++)
                {
                    newGraph[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                }
            }
        }
        Graph g;
        g.loadGraph(newGraph);
        return g;
    }

    Graph Graph::operator*=(Graph &other) 
    {
        size_t g1hSize = getSize();
        if (g1hSize != other.getSize())
        {
            throw invalid_argument(" Invalid_argument-The graphs are not the same size.");
        }

        size_t size = getSize();
        std::vector<std::vector<int>> newGraph(g1hSize, std::vector<int>(g1hSize, 0));
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                for (size_t k = 0; k < size; k++)
                {
                    newGraph[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                }
            }
        }
        adjMatrix = newGraph;
        return *this;
        
    }

    Graph Graph::operator*(int scalar)
    {
        size_t size = getSize();
        std::vector<std::vector<int>> newGraph(size, std::vector<int>(size, 0));
        
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j] *= scalar;
            }
        }
        Graph g;
        g.loadGraph(newGraph);
        return g;
    }

    Graph Graph::operator*=(int scalar)
    {
        size_t size = getSize();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                adjMatrix[i][j] *= scalar;
            }
        }
        return *this;
    }
///print //////

    std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        if(graph.adjMatrix.empty()){
            os << "The graph is empty." << endl;
            return os;
        }
        
        size_t numVertices = graph.adjMatrix.size();

        for (size_t i = 0; i < numVertices; i++)
        {
            for (size_t j = 0; j < numVertices; j++)
            {
                os << graph.adjMatrix[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }















} // namespace ariel
