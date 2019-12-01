//
// Created by ad26 on 11/30/19.
//

#include "flowGraph.h"

flowGraph :: flowGraph(int num_of_vertices){
    this->num_of_vertices = num_of_vertices;
    this->num_of_edges = 0;
    adjList.resize(num_of_vertices);
}

void flowGraph :: addEdge(flowEdge e){
    adjList[e.from].push_back(e);
    adjList[e.to].push_back(e);
    this->num_of_edges ++;
}
std::vector<flowEdge> flowGraph :: returnConnections(int vertex){
    return adjList[vertex];
}