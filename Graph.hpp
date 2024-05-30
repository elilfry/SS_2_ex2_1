/*
211691159
elifrydman08@gmail.com
*/

#pragma once

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;


namespace ariel{
class Graph {
    private:
    std::vector<std::vector<int>> adjMatrix; 

    public:

//load graph
/*
the function load the graph to the object
*/
void loadGraph(const std::vector<std::vector<int>>& graph);

/*
the function return the neighbors of the vertex
@param vertex the vertex
@return the neighbors of the vertex.
*/
std::vector<int> getNeighbors(size_t vertex) ;

size_t getSize()  const;


/*

the function print the graph
*/
string printGraph();

size_t getNumberOfEdges();

size_t getNumberOfVertices();



bool isWeightedGraph();

bool isDirectedGraph();

bool isNegativeWeightedGraph();

int getWeight(size_t src, size_t dest);
 




// Aritmetic operators
/*
@brief operator- + binary add 2 graphs
@param other the other graph
@return  Graph the sum of the 2 graphs
@throw invalid_argument if the graphs can't be added(not the same size)
*/
Graph operator+( Graph& other);
//+=
/*
@brief operator- += add the other graph to the current graph
@param other the other graph
@return the current graph after the adding the other graph
*/
Graph operator+=( Graph& other);
// unary +
/*
@brief operator- + unary does nothing
*/
Graph operator+(); //does nothing  
//-
/*
@brief operator- - binary subtract 2 graphs
@param other the other graph
@return  Graph the subtract of the 2 graphs
@throw invalid_argument if the graphs can't be subtracted(not the same size)
*/
Graph operator-( Graph& other);
// -=
/*
@brief operator- -= subtract the other graph to the current graph
@param other the other graph
@return the current graph after the subtracting the other graph
@throw invalid_argument if the graphs can't be subtracted(not the same size)
*/
Graph operator-=( Graph& other);
// unary -
/*
@brief operator- - unary negate the graph
@return  Graph the negate of the graph
*/
Graph operator-(); //negate the graph


//comerison operators
/*
@brief operator- == compare 2 graphs
@return  bool true if the graphs are equal, false otherwise
*/
bool operator==(const  Graph& other) const ;
//!=
/*
@brief operator- != compare 2 graphs
@return  bool true if the graphs are not equal, false otherwise
*/
bool operator!=( const Graph& other) const;
//> 
/*
@brief operator- > compare 2 graphs and check if the graph is greater then the other graph - other is a subgraph of the graph
@return  bool true if the graph is greater then the other graph-other is a subgraph of the graph, false otherwise
*/
bool operator>(const Graph& other) const ;
//<
/*
@brief operator- < compare 2 graphs and check if the graph is less then the other graph - graph is a subgraph of the other
@return  bool true if the graph is less then the other graph-graph is a subgraph of the other, false otherwise
*/
bool operator<(const Graph& other) const ;
//>=
bool operator>=(const Graph& other) const ;
//<=
bool operator<=(const  Graph& other) const ;


//prefix increment ++i
/*
@brief operator- ++  prefix increment the graph
*/
Graph operator++(); 
// postfix increment i++
/*
@brief operator- ++  postfix increment the graph
*/
Graph operator++(int); 
//prefix decrement --i
/*
@brief operator- --  prefix decrement the graph
*/
Graph operator--();
// postfix decrement i--
/*
@brief operator- --  postfix decrement the graph
*/
Graph operator--(int);

//multip by scalar
Graph operator*(int scalar);

//multio by scalar and assign
Graph operator*=(int scalar);

//multip 2 graphs
Graph operator*( Graph& other);

//*=
Graph operator*=( Graph& other); //multip 2 graphs

//check if the graph can be multip by other graph

//print the graph
friend std::ostream& operator<<(std::ostream& os, const Graph& graph);































































};
}

#endif //GRAPH_HPP