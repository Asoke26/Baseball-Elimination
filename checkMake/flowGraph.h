//
// Created by ad26 on 12/3/19.
//

#ifndef BASEBALL_ELIMINATION_FLOWGRAPH_H
#define BASEBALL_ELIMINATION_FLOWGRAPH_H

#include <vector>
#include "flowEdge.h"

class flowGraph {
public:
    int num_of_vertices;
    int num_of_edges;

    std::vector < std::vector<flowEdge> > adjList;

    flowGraph(int num_of_vertices);
    void addEdge(flowEdge e);
    std::vector<flowEdge> returnConnections(int vertex);
};


#endif //BASEBALL_ELIMINATION_FLOWGRAPH_H
