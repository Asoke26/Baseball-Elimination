#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <bits/stdc++.h>

#include "flowEdge.h"
#include "flowGraph.h"
#include "fordFulkerson.h"
using namespace std;

int MAX_NUM_WINS = 0;
int NUM_OF_TEAMS = 0;

//*********************************************//
vector<int> wins;
vector<int> losses;
vector<int> remaining;
vector<bool> isEliminated;

vector<vector<int>> games;
//*********************************************//

void trivialElimination();
bool buildFlowNetwork(int id);

int main(int argc, char *argv[]) {

    vector<int> eliminated;
    vector<int> survived;

    /************************** Start Input file Preprocessing*********************************************/
    ifstream infile;
    infile.open(argv[1]);

    if (infile.is_open()){
        cout<<"Input file opened successfully "<<endl;
    }
    else{
        cout<<"File not loaded"<<endl;
    }


    string test;
    getline(infile,test);
    NUM_OF_TEAMS =  stoi(test);
    int check = NUM_OF_TEAMS;

    for (int i =0;i<NUM_OF_TEAMS ;i++)
    {
        getline(infile,test);
        vector<int> tempVec;
        string temp = "";
        for(int i =0;i<test.length();i++){
            if(test[i] == ' ' && temp.size() > 0){
                tempVec.push_back(stoi(temp));
                temp = "";
            }
            else if(test[i] != ' ' ){
                temp+=test[i];
            }

            if(i==test.length()-1){
                int temp_val = stoi(temp);
                tempVec.push_back(temp_val);
                temp = "";
            }
        }


        int id = tempVec[0];
        wins.push_back(tempVec[1]);
        losses.push_back(tempVec[2]);
        remaining.push_back(tempVec[3]);

        games.push_back(vector<int>());
        for(int i = 4; i<tempVec.size();i++)
        {
            games[id].push_back(tempVec[i]);
        }

    }
    infile.close();
    /***************************End Input file Processing************************************************/

    trivialElimination(); // Chekcing Trivial elimination condition

    for(int i = 0; i<isEliminated.size();i++)
    {
        if(isEliminated[i]) eliminated.push_back(i);
    }
    cout<<endl;

    // 2. Build Flow Graph
    for(int i=0;i<NUM_OF_TEAMS;i++)
    {
        if(isEliminated[i] ==1) continue;
        else{
            bool result = buildFlowNetwork(i);
            if(result == true)survived.push_back(i);
            else eliminated.push_back(i);
        }
    }

    // Checked Input : 4,4a,12,60,8
    cout<<"###############################Teams Eliminated###############################"<<endl;
    sort(eliminated.begin(),eliminated.end());
    if(eliminated.size() ==0) cout<<"-1"<<endl;
    else{
        for(int i=0;i<eliminated.size();i++){
            cout<<eliminated[i]<<" ";
        }
        cout<<endl;
    }


    cout<<"###############################Teams Not Eliminated###############################"<<endl;
    sort(survived.begin(),survived.end());
    for(int i=0;i<survived.size();i++){
        cout<<survived[i]<<" ";
    }
    cout<<endl;

    return 0;
}




void trivialElimination()
{
    int MAX_WINS = *max_element(wins.begin(),wins.end());

    for(int i =0; i < NUM_OF_TEAMS; i++)
    {
        if (wins[i] + remaining[i] < MAX_WINS)
        {
            isEliminated.push_back(1);
        }
        else{
            isEliminated.push_back(0);
        }
    }

}

bool buildFlowNetwork(int id)
{
    int source = NUM_OF_TEAMS;
    int sink = NUM_OF_TEAMS+1;
    int number_of_nodes = 2;
    int gameNode = NUM_OF_TEAMS+2;

    int possibleMaxWin = wins[id] + remaining[id];
    vector<flowEdge> all_edges;

    for(int i=0;i<NUM_OF_TEAMS;i++){
        if(i == id || wins[i]+remaining[i] < MAX_NUM_WINS || i+1 == NUM_OF_TEAMS) continue;
        for(int j=i+1;j<NUM_OF_TEAMS;j++)
        {
            if(j == id || wins[i]+remaining[i] < MAX_NUM_WINS || games[i][j] ==0 ) continue;

            all_edges.push_back(flowEdge(source,gameNode,games[i][j],0));
            all_edges.push_back(flowEdge(gameNode,i,INT8_MAX,0));
            all_edges.push_back(flowEdge(gameNode,j,INT8_MAX,0));
            number_of_nodes++;
            gameNode++;
        }
    }

    for(int i=0;i<NUM_OF_TEAMS;i++)
    {
        if(i == id )continue;
        all_edges.push_back(flowEdge(i,sink,possibleMaxWin-wins[i],0));
        number_of_nodes++;
    }

    flowGraph flow_network(number_of_nodes+1);

    for (int i=0 ;i <all_edges.size();i++)
    {
        flow_network.addEdge(all_edges[i]);
    }

    fordFulkerson ff(flow_network, source,sink);

    // Check if all edges connected from source are saturated or not
    for(int i=0;i<flow_network.adjList[source].size();i++){
        if(flow_network.adjList[source][i].capacity != 0){
            return false;
        }
    }
    return true;

}