//
// Created by ad26 on 12/3/19.
//

#include "flowEdge.h"

flowEdge :: flowEdge(int from,int to,int capacity,int flow){
    this->from = from;
    this->to = to;
    this->capacity = capacity;
    this->flow = flow;
}

int flowEdge :: resuidalCapacityto(int vertex){
    if (vertex == this->from) return this->flow;
    else if (vertex == this->to) return this->capacity - this->flow;
}

void flowEdge :: addResidualFLowto(int vertex , int delta){
    if (vertex == this->from) this->flow -= delta;
    else if (vertex == this->to) this->flow +=delta;
}