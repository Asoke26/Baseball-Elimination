#include<iostream>
#include<queue>
using namespace std;

int main()
{
	/*This function implementation checks if there is a shortest augmenting 
	path between the source and sink in the given FlowGraph G*/
	bool augpath(FlowGrpah G,int source, int sink) 
	{
		edge_to=FlowEdge[G.V()];
		marked_edge=bool m_e[G.V()];
		
		/*Travese the graph using breadth first search to find the augmenting path*/
		queue <int> que; //create a queue of integer type
		que.push(source) //push the source node received from the function parameter
		marked_edge[source]=true; //mark source node to be visited
		
		//run while loop till the sink is reached and while the queue is not empty
		while(!(que.empty()) && !(marked_edge[sink])) 
		{
			int v=que.pop();
			//here the for each loop iterates through the flowgraph G( where adj returns the edge to v)
			for(FlowGraph e:G.adj(v))
			{
				int w=e.other(v);
				//here the other method of flowedge returns the the other end vertex of v through edge e
				
				/*here we check for nonzero resudialcapacity of edge e 
				through the residualCapacityTo function of FlowEdge*/
				if(e.resudialCapacityTo(w)>0)
				{ 
					if(!marked_edge[w])
					{
						edge_to[w]=e;
						marked_edge[w]=true;
						que.push(w);	
					}
				}	
			} 			
		}
		/*If there exist a augmenting path return the marked_edge boolean array*/
		return marked_edge[t];	
	}
	return 0;
}
