#ifndef BASEBALL_ELIMINATION_FORDFULKERSON_H
#define BASEBALL_ELIMINATION_FORDFULKERSON_H

#include <vector>
#include <queue>

#include "flowGraph.h"
#include "flowEdge.h"

using namespace std;

class fordFulkerson {
public:
    int flow;
    vector<bool> marked;
    vector<flowEdge> edge_to;
    int bottle_neck;

    fordFulkerson(flowGraph &network, int source, int terget);

    bool hasAugmentingPath(flowGraph network,int source,int sink);

    flowGraph updateFlowGraph(flowGraph network,vector <flowEdge> &edges);

};


#endif //BASEBALL_ELIMINATION_FORDFULKERSON_H
