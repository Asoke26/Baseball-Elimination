//
// Created by ad26 on 12/4/19.
//

#include <iostream>
#include "fordFulkerson.h"

using namespace std;

fordFulkerson ::fordFulkerson(flowGraph &network, int source, int terget) {

    marked.resize(network.num_of_vertices, false);
    edge_to.resize(network.num_of_vertices);

    while (hasAugmentingPath(network,source,terget) && marked[terget]){
        // Find the augmenting path and bottleneck
        vector<flowEdge> aug_path;
        bottle_neck =99999;

        for(int current = terget; current!=source;current= edge_to[current].other(current)){
            if(edge_to[current].to == 0 && edge_to[current].from == 0) continue;
            aug_path.push_back(edge_to[current]);
            if(bottle_neck > edge_to[current].capacity)bottle_neck = edge_to[current].capacity;
//            cout<<"----- Aug Path --- "<<edge_to[current].to<<" "<<edge_to[current].from<<endl;
        }
//        cout<<"Size of augmenting path "<<aug_path.size()<<bottle_neck<<endl;
//        for(int i =0;i<edge_to.size();i++){
//            cout<<"Edge to --- "<<edge_to.size()<<"  ---- "<<edge_to[i].to<<" "<<edge_to[i].from<<endl;
//        }


        // Update the flowGraph
        network = updateFlowGraph(network,aug_path);
        aug_path.clear();
        edge_to.clear();
        marked[terget] = false;
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
                edge.parent = v;
                edge_to[w] = edge;
                marked[w] = true;
                bfs_queue.push(w);
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