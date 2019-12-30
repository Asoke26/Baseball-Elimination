#include <iostream>
#include "fordFulkerson.h"

using namespace std;

fordFulkerson ::fordFulkerson(flowGraph &network, int source, int terget) {

    marked.resize(network.num_of_vertices, false);
    edge_to.resize(network.num_of_vertices);

    while (hasAugmentingPath(network,source,terget)){
        if(!marked[terget]) break;
        // Find the augmenting path and bottleneck
        vector<flowEdge> aug_path;
        bottle_neck =99999;

        vector<bool> visited(network.num_of_vertices,false);
        int current = terget;

        while( current!=source){
            if(edge_to[current].to == 0 && edge_to[current].from == 0) continue;
            aug_path.push_back(edge_to[current]);
            if(bottle_neck > edge_to[current].capacity)bottle_neck = edge_to[current].capacity;
            current= edge_to[current].other(current);
        }

        // Update the flowGraph
        network = updateFlowGraph(network,aug_path);
        aug_path.clear();
        edge_to.clear();
        marked.clear();
        marked.resize(network.num_of_vertices, false);
    }
}

bool fordFulkerson ::hasAugmentingPath(flowGraph network, int source, int sink) {
    queue<int> bfs_queue;
    bfs_queue.push(source);
    marked[source] = true;


    while(!bfs_queue.empty() && !marked[sink]){
        int v = bfs_queue.front();

        bfs_queue.pop();

        for(flowEdge edge : network.returnConnections(v)){
            int w = edge.other(v);
             if(edge.capacity > 0 && !marked[w]){
                edge_to[w] = edge;
                marked[w] = true;
                bfs_queue.push(w);
            }
            else if(edge.capacity > 0 && !marked[v] && v == sink){
                edge_to[v] = edge;
                marked[v] = true;
            }
        }

    }


    return marked[sink];
}

flowGraph fordFulkerson ::updateFlowGraph(flowGraph network, vector<flowEdge> &edges) {
    for(int i=0;i<network.adjList.size();i++){
        for(int j=0;j<network.adjList[i].size();j++){
            for(int k=0;k<edges.size();k++){
                if(edges[k].to == network.adjList[i][j].to && edges[k].from == network.adjList[i][j].from){
                    network.adjList[i][j].capacity -=  bottle_neck;
                    network.adjList[i][j].flow += bottle_neck;
                }
            }
        }
    }
    return network;
}