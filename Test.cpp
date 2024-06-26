/*
211691159
elifrydman08@gmail.com
*/

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph addition with different dimensions")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1},
        {1, 0}};
    g2.loadGraph(weightedGraph);
    CHECK_THROWS_WITH(g1 + g2, "Invalid_argument-The graphs are not the same size");
    //CHECK_THROWS(g1 + g2);
}

    TEST_CASE("Test graph subtraction")
    {
        ariel::Graph g1;
        vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(graph);
        ariel::Graph g2;
        vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
        g2.loadGraph(weightedGraph);
        ariel::Graph g3 = g1 - g2;
        
        CHECK(g3.printGraph() == "[0, 0, -1]\n[0, 0, -1]\n[-1, -1, 0]");
    }

    TEST_CASE("Test graph equality")
    {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(graph1);

        ariel::Graph g2;
        vector<vector<int>> graph2 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g2.loadGraph(graph2);

        CHECK(g1 == g2);
    }

    TEST_CASE("Test graph inequality")
    {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(graph1);

        ariel::Graph g2;
        vector<vector<int>> graph2 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 1, 0}};
        g2.loadGraph(graph2);

        CHECK(g1 != g2);
    }

    TEST_CASE("Test pre-increment operator")
    {
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph);

        ariel::Graph g1 = ++g;
        CHECK(g1.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
        CHECK(g.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
    }

    TEST_CASE("Test post-increment operator")
    {
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph);

        ariel::Graph g1 = g++;
        CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
        CHECK(g.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
    }

    TEST_CASE("Test pre-decrement operator")
    {
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph);

        ariel::Graph g1 = --g;
        CHECK(g1.printGraph() == "[-1, 0, -1]\n[0, -1, 0]\n[-1, 0, -1]");
        CHECK(g.printGraph() == "[-1, 0, -1]\n[0, -1, 0]\n[-1, 0, -1]");
    }

    TEST_CASE("Test post-decrement operator")
    {
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph);

        ariel::Graph g1 = g--;
        CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
        CHECK(g.printGraph() == "[-1, 0, -1]\n[0, -1, 0]\n[-1, 0, -1]");
    }


TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");
}


TEST_CASE("Test <=")
{
    ariel::Graph g1;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph2); 

    ariel::Graph g2;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g2.loadGraph(graph3); 

    CHECK(g1 <= g2);
}

// TEST_CASE("Test graph multiplication with different dimensions")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1, 1},
//         {1, 0, 2, 1},
//         {1, 2, 0, 1}};
//     g2.loadGraph(weightedGraph);
//     CHECK_THROWS(g1 * g2);
// }

// TEST_CASE("Invalid operations")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1, 1},
//         {1, 0, 2, 1},
//         {1, 2, 0, 1}};
//     g2.loadGraph(weightedGraph);
//     ariel::Graph g5;
//     vector<vector<int>> graph2 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g5.loadGraph(graph2);
//     CHECK_THROWS(g5 * g1);
//     CHECK_THROWS(g1 * g2);

//     // Addition of two graphs with different dimensions
//     ariel::Graph g6;
//     vector<vector<int>> graph3 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g6.loadGraph(graph3);
//     CHECK_THROWS(g1 + g6);
// }   



////////////////////////////////////////// EX1 TESTS //////////////////////////////////////////

////////////////////////////////////////// EX1 TESTS //////////////////////////////////////////
TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "The shortest path from 0 to 2 is: 0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "No path exists between the source and destination vertices");

     vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == "Negative cycle exists in the graph");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The graph does not contain a cycle");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");

    vector<vector<int>> graph3 = { // Directed graph with negative cycle
        {0, 0, 1},
        {-5, 0, 0},
        {0, 2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->1->0");

    

    vector<vector<int>> graph4 = { // Directed graph with a cycle
        {0, 0, 0},
        {0, 0, -20},
        {0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 1->2->1");

    

    vector<vector<int>> graph5 = { // Directed graph without a cycle
        {0, 0, -1},
        {0, 0, 2},
        {0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The graph does not contain a cycle");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");


    vector<vector<int>> graph4 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph1));

    vector<vector<int>> graph2 = {
        {0, 1, 2, 0},
        {1, 2, 3, 0},
        {2, 3, 1, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph2));


    
}

TEST_CASE("Test empty graph") {
    ariel::Graph g;
    // No need to load any graph here, it's empty by default
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "The graph is empty");  // Empty graph has no path
    CHECK(ariel::Algorithms::isConnected(g) == false);  // Empty graph is not connected
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The graph does not contain a cycle");  // Empty graph has no cycles
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={}, B={}");  // Empty graph is bipartite
}

TEST_CASE("Test shortestPath for longer path") {
  ariel::Graph g;
  vector<vector<int>> graph = {
      {0, 1, 0, 0, 0},
      {1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0},
      {0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0}};
  g.loadGraph(graph);
  CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "The shortest path from 0 to 4 is: 0->1->3->4");
}

TEST_CASE("Test negativeCycle") {
     ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK( ariel::Algorithms::negativeCycle(g) == "No negative cycle.");

    vector<vector<int>> graph2 = {// negative edges but cycle is not negative
                                  {0, 1, -3, 0, 0},
                                  {0, 0, 0, 2, 0},
                                  {0, 0, 0, 0, 3},
                                  {0, -1, 0, 0, 0},
                                  {0, 0, 0, -2, 0}};
    g.loadGraph(graph2);
    CHECK( ariel::Algorithms::negativeCycle(g) == "No negative cycle.");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK( ariel::Algorithms::negativeCycle(g) == "Negative cycle exists in the graph");

    
}
