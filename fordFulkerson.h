//
// Created by ad26 on 12/2/19.
//

#ifndef BASEBALL_ELIMINATION_FORDFULKERSON_H
#define BASEBALL_ELIMINATION_FORDFULKERSON_H

#include <vector>
#include "flowEdge.h"
#include "flowGraph.h"

using namespace std;

class fordFulkerson {
    int vertex;

    vector <flowEdge> edges;
    int count_flow;

    int ford_Fulkerson_algo(flowGraph G, int source, int terget);
    bool hasAugmentingPath(flowGraph G, int source,int terget);
    int excess(flowGraph G, int v);

};


#endif //BASEBALL_ELIMINATION_FORDFULKERSON_H
