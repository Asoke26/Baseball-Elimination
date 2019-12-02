#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "flowEdge.h"
#include "flowGraph.h"
#include <unordered_set>


using namespace std;
template <typename team>

int MAX_NUM_WINS = 0;

/*Creating a data structure to hold each team stat*/
class team
{
    public:
    int name; // Team name
    int wins; // Number of wins
    int losses; // Number of losses
    int remaining; // Number of remaining matches
    bool isEliminated;

    vector<int> against; // Remaining with whom

    team(){
        name = -1;
        wins = 0;
        losses = 0;
        remaining = 0;
        isEliminated = false;
    }

    void team_print(){
        cout<<"Name # "<<name<<endl;
        cout<<"Wins #"<<wins<<endl;
        cout<<"Losses # "<<losses<<endl;
        cout<<"Remaining # "<<remaining<<endl;
        cout<<"Is Eliminated # "<<boolalpha<<isEliminated<<endl;
        cout<< "Max number of wins among all team # "<<MAX_NUM_WINS<<endl;
        cout<<"Against stat: ";
        for(int i =0; i<against.size();i++)
        {
            cout<<against[i]<<" ";
        }
        cout<<endl;
    }
};

team process_input(string line,int number_of_teams);
void trivialElimination(vector<team> &all_teams);
flowGraph buildGraphfor(int team, int NUM_OF_TEAMS);

int main(int argc, char *argv[]) {
    vector<team> all_teams;


    /************************** Start Input file Processiiing*********************************************/
    ifstream infile;
    infile.open(argv[1]);

    if (infile.is_open()){
        cout<<"File opened successfully "<<endl;
    }
    else{
        cout<<"File not loaded"<<endl;
    }


    string test;
    int NUM_OF_TEAMS;
    int first_line=0;
    int *game;
    while (infile){
        first_line ++;
        getline(infile,test);
        if(first_line == 1){
            NUM_OF_TEAMS =  stoi(test);
            game = new int[NUM_OF_TEAMS*NUM_OF_TEAMS];
        }
        else{
            team t1= process_input(test,NUM_OF_TEAMS);
            all_teams.push_back(t1);
        }
    }
    infile.close();
    /***************************End Input file Processiiing************************************************/

    // Update game matrix
    for (int i =0; i < all_teams.size();i++)
    {
        for(int j = 0; j< all_teams[i].against.size();j++){
            game[i*NUM_OF_TEAMS + j] = all_teams[i].against[j];
        }
    }


    trivialElimination(all_teams); // Chekcing Trivial elimination condition

    for (int i =0; i < all_teams.size();i++)
    {
        all_teams[i].team_print();
    }




    return 0;
}

/*Processing Input*/
team process_input(string line,int number_of_teams)
{
    team sample_team;
    string temp="";
    vector <int> tempVec;
    for(int i =0;i<line.length();i++){
        if(line[i] == ' '){
            tempVec.push_back(stoi(temp));
            temp = "";
        }
        else{
            temp+=line[i];
        }

        if(i==line.length()-1){
            tempVec.push_back(stoi(temp));
            temp = "";
        }
    }
    // Assigning value to the data-structure
    sample_team.name = tempVec[0];
    sample_team.wins = tempVec[1];
    sample_team.losses = tempVec[2];
    sample_team.remaining = tempVec[3];

    // Getting Maximum wins among all the teams
    if (sample_team.wins > MAX_NUM_WINS) MAX_NUM_WINS = sample_team.wins;

    for(int i=4;i<tempVec.size();i++)sample_team.against.push_back(tempVec[i]);

    return sample_team;
}


void trivialElimination(vector<team> &all_teams)
{
    for (int i =0; i < all_teams.size();i++)
    {
        if (all_teams[i].wins + all_teams[i].remaining < MAX_NUM_WINS)
            all_teams[i].isEliminated = true;
    }
}

flowGraph buildGraphfor(int team, int NUM_OF_TEAMS){
    int source = NUM_OF_TEAMS;
    int sink = NUM_OF_TEAMS + 1;
    int gameNode = NUM_OF_TEAMS + 2;

    int possibleMaxwin =
    unordered_set<flowEdge> edges;

    int

}