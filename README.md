# System Programming 2 - Assignment 2

## Eli Frydman

### Graph Algorithms Enhancement

This project extends the initial graph algorithms library with additional functionality and improved features. It builds upon the foundation laid in Assignment 1, adding more capabilities and enhancing existing ones.

### Features

#### Graph Connectivity:
- **Check if a graph is connected**: Determines whether there is a path between every pair of vertices.

#### Cycle Detection:
- **Identify cycles in both directed and undirected graphs**.

#### Shortest Path Calculation:
- **BFS (Breadth-First Search)**: Ideal for unweighted graphs.
- **Dijkstra's Algorithm**: Suitable for graphs with non-negative weights.
- **Bellman-Ford Algorithm**: Handles graphs with negative weights and can detect negative weight cycles.

#### Bipartite Graph Check:
- **Determine if a graph is bipartite**: Meaning its vertices can be divided into two disjoint sets such that no two graph vertices within the same set are adjacent.

#### Negative Cycle Detection:
- **Check for negative cycles in the graph**: Cycles with a total negative weight.

#### Graph Operations:
- **Perform arithmetic and comparison operations on graphs**, such as addition, subtraction, and multiplication.
- **Check if graphs are equal, subgraphs of one another, or have the same structure**.

### Files

#### Algorithms.hpp

- **Functions**

  - `static int Algorithms::isConnected(Graph graph)`
    - **Description**: Checks if the graph is connected.
    - **Parameters**: `graph` - A Graph object.
    - **Output**: 1 if the graph is connected, 0 otherwise.

  - `static void Algorithms::dfs(Graph& graph, std::vector<bool>& visited, size_t node)`
    - **Description**: Performs a depth-first search on the graph.
    - **Parameters**: 
      - `graph` - A Graph object.
      - `visited` - A vector indicating which vertices have been visited.
      - `node` - The starting vertex for the DFS traversal.

  - `static bool Algorithms::isCycleUndirected(Graph& graph, size_t node, int parent, std::vector<bool>& visited, std::vector<int>& path)`
    - **Description**: Checks for cycles in an undirected graph.
    - **Parameters**: 
      - `graph` - A Graph object.
      - `node` - Current node.
      - `parent` - Parent node.
      - `visited` - A vector indicating visited vertices.
      - `path` - A vector storing the current path for cycle detection.
    - **Output**: true if a cycle is detected, false otherwise.

  - `static bool Algorithms::isCycleDirected(Graph& graph, size_t node, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& path)`
    - **Description**: Checks for cycles in a directed graph.
    - **Parameters**: 
      - `graph` - A Graph object.
      - `node` - Current node.
      - `visited` - A vector indicating visited vertices.
      - `recStack` - A recursion stack to track nodes in the current recursion stack.
      - `path` - A vector storing the current path for cycle detection.
    - **Output**: true if a cycle is detected, false otherwise.

  - `static string Algorithms::isContainsCycle(Graph& graph)`
    - **Description**: Determines if the graph contains a cycle and returns the cycle path if one exists.
    - **Parameters**: `graph` - A Graph object.
    - **Output**: A string describing a cycle if one exists, otherwise "The graph does not contain a cycle."

  - `static string Algorithms::shortestPath(Graph& graph, size_t start, size_t end)`
    - **Description**: Finds the shortest path between two vertices.
    - **Parameters**: 
      - `graph` - A Graph object.
      - `start` - Start vertex index.
      - `end` - End vertex index.
    - **Output**: A string describing the shortest path between the vertices.

  - `static string Algorithms::bfs(Graph& graph, size_t src, size_t dest)`
    - **Description**: Uses BFS to find the shortest path in an unweighted graph.
    - **Parameters**: 
      - `graph` - A Graph object.
      - `src` - Source vertex index.
      - `dest` - Destination vertex index.
    - **Output**: A string describing the shortest path using BFS.

  - `static string Algorithms::bellmanFord(Graph& graph, size_t src, size_t dest)`
    - **Description**: Uses Bellman-Ford to find the shortest path in a graph with negative weights.
    - **Parameters**: 
      - `graph` - A Graph object.
      - `src` - Source vertex index.
      - `dest` - Destination vertex index.
    - **Output**: A string describing the shortest path using Bellman-Ford algorithm.

  - `static string Algorithms::dijkstra(Graph& graph, size_t src, size_t dest)`
    - **Description**: Uses Dijkstra's algorithm to find the shortest path in a graph with non-negative weights.
    - **Parameters**: 
      - `graph` - A Graph object.
      - `src` - Source vertex index.
      - `dest` - Destination vertex index.
    - **Output**: A string describing the shortest path using Dijkstra's algorithm.

  - `static string Algorithms::isBipartite(Graph& graph)`
    - **Description**: Checks if the graph is bipartite.
    - **Parameters**: `graph` - A Graph object.
    - **Output**: A string describing whether the graph is bipartite and the two groups of vertices.

  - `static string Algorithms::negativeCycle(Graph& graph)`
    - **Description**: Checks for the existence of a negative cycle in the graph.
    - **Parameters**: `graph` - A Graph object.
    - **Output**: A string indicating if a negative cycle exists.

#### Graph.hpp

- **Functions**

  - `void Graph::loadGraph(const std::vector<std::vector<int>>& graph)`
    - **Description**: Loads the graph from the given adjacency matrix.
    - **Parameters**: `graph` - A square matrix representing the graph.

  - `void Graph::printGraph()`
    - **Description**: Prints the adjacency matrix of the graph.

  - `bool Graph::isWeightedGraph()`
    - **Description**: Checks if the graph contains weights other than 0 and 1.
    - **Output**: true if the graph is weighted, false otherwise.

  - `bool Graph::isDirectedGraph()`
    - **Description**: Checks if the graph is directed by verifying if the adjacency matrix is symmetric.
    - **Output**: true if the graph is directed, false otherwise.

  - `size_t Graph::getNumberOfEdges()`
    - **Description**: Counts the number of edges in the graph.
    - **Output**: The number of edges in the graph.

  - `std::vector<int> Graph::getNeighbors(size_t vertex)`
    - **Description**: Returns a list of vertices adjacent to the given vertex.
    - **Parameters**: `vertex` - A vertex index.
    - **Output**: A list of neighbors (adjacent vertices).

  - `size_t Graph::getSize() const`
    - **Description**: Returns the number of vertices in the graph.
    - **Output**: The number of vertices in the graph.

  - `bool Graph::isNegativeWeightedGraph()`
    - **Description**: Checks if the graph contains any negative edge weights.
    - **Output**: true if the graph has negative weights, false otherwise.

  - `int Graph::getWeight(size_t src, size_t dest)`
    - **Description**: Returns the weight of the edge from src to dest.
    - **Parameters**: 
      - `src` - Source vertex index.
      - `dest` - Destination vertex index.
    - **Output**: The weight of the edge from src to dest.

### Arithmetic and Comparison Operators

#### Arithmetic Operators

- **Addition**: Adds two graphs element-wise.
  - `Graph Graph::operator+(Graph &other)`
  - `Graph Graph::operator+=(Graph &other)`

- **Subtraction**: Subtracts one graph from another element-wise.
  - `Graph Graph::operator-(Graph &other)`
  - `Graph Graph::operator-=(Graph &other)`

- **Unary Plus**: Returns the graph itself.
  - `Graph Graph::operator+()`

- **Unary Minus**: Negates all elements of the graph.
  - `Graph Graph::operator-()`

- **Multiplication**: Multiplies two graphs or a graph by a scalar.
  - `Graph Graph::operator*(Graph &other)`
  - `Graph Graph::operator*=(Graph &other)`
  - `Graph Graph::operator*(int scalar)`
  - `Graph Graph::operator*=(int scalar)`

#### Comparison Operators

- **Equality**: Checks if two graphs are equal.
  - `bool Graph::operator==(const Graph &other) const`

- **Inequality**: Checks if two graphs are not equal.
  - `bool Graph::operator!=(const Graph &other) const`

- **Less Than**: Checks if the graph is less than another graph.
  - `bool Graph::operator<(const Graph &other) const`

- **Less Than or Equal**: Checks if the graph is less than or equal to another graph.
  - `bool Graph::operator<=(const Graph &other) const`

- **Greater Than**: Checks if the graph is greater than another graph.
  - `bool Graph::operator>(const Graph &other) const`

- **Greater Than or Equal**: Checks if the graph is greater than or equal to another graph.
  - `bool Graph::operator>=(const Graph &other) const`

#### Increment and Decrement Operators

- **Prefix Increment**: Increments all elements of the graph by 1.
  - `Graph Graph::operator++()`

- **Postfix Increment**: Increments all elements of the graph by 1.
  - `Graph Graph::operator++(int)`

- **Prefix Decrement**: Decrements all elements of the graph by 1.
  - `Graph Graph::operator--()`

- **Postfix Decrement**: Decrements all elements of the graph by 1.
  - `Graph Graph::operator--(int)`

#### Output Stream Operator

- **Output Stream**: Prints the graph's adjacency matrix to an output stream.
  - `std::ostream &operator<<(std::ostream &os, const Graph &graph)`

### How to Run

1. Clone the repository.
2. Ensure you have a compatible C++ compiler.
3. Compile the source files.
4. Run the executable to test the functionalities.

### Dependencies

- C++ Standard Library

### Author

Eli Frydman
