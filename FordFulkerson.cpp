#include<assert.h>
#include<array>
class FF
{
	private bool marked_edge[]; //boolean array to keep track of marked edges
	private FlowEdge edge_to[]; //recent edge between the source and v
	private double value; // current value for max flow
	
	public FF(FlowNetwork G, int src, int snk)
	{
		validate(src,G.V()); //check for the index out of bound exception
		validate(snk,G.V()); //check for the index out of bound exception
		
		if(src==snk) //Check source and sink the same exception
		{
			cout<<"Source and sink are the same"<<" "<<"Exiting"<<endl;
			exit(0);	
		}
		if(!isFeasible(G,src,snk))  //Check is the flow is even possible
		{
			cout<<"Initial flow impossible"<<" "<<"Exiting"<<endl;
			exit(0);
		}
		
		value=excess(G,snk);
		
		while(augpath(G,src,snk))
		{
			double bottle_neck=INFINITY;
			int v;
			for(v=sink;v!=source;v=edge_to[v].other(v))
			{
				bottle_neck=std::min(bottle_neck,edge_to[v].residualCapacityTo(v));//check minimum residual capacity to the vertx v in the given direction
			}
			
			for(v=sink;v!=source;v=edge_to[v].other(v)) //add the flow
			{
				edge_to[v].addResidualFlowTo(v,bottle);
			}
			
			value+=bottle_neck;
		}
		
		assert check(G,source,sink);	
	}
	
	public double value()
	{
		return value;
	}
	
	public bool inCut(int v)
	{
		validate(v,sizeof(marked_edge));
		return marked_edge[v];
	}
	
	private void validate(int v,int V)
	{
		if(v<0||v>=V)
		{
			cout<<"Vertex out of bound exception"<<"Exiting"<<endl;
			exit(0)
		}
	}
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
	
	double excess (FlowNetwork G,int v)
	{
		double excess=0.0;
		for(FlowEdge e:G.adj(v))
		{
			if(v==e.from())
			{
				excess-=e.flow();
			}
			else
			{
				excess+=e.flow();
			}
		}
		return excess;
	}	
}
