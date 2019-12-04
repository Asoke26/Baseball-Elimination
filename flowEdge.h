//
// Created by ad26 on 12/3/19.
//

#ifndef BASEBALL_ELIMINATION_FLOWEDGE_H
#define BASEBALL_ELIMINATION_FLOWEDGE_H


class flowEdge {
public:
    int from;
    int to;
    int capacity;
    int flow;

    flowEdge(int from,int to,int capacity,int flow);

    int resuidalCapacityto(int vertex);

    void addResidualFLowto(int vertex , int delta);
};


#endif //BASEBALL_ELIMINATION_FLOWEDGE_H
