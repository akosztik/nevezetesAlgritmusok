#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>



using namespace std;

int GraphFiller(vector<vector<int> > &Graph, ifstream &f ,vector<int> &kifok, vector<int> &befok, int utNum);
int MB(vector<vector<int> >& Graph,stack<int>& s,vector<int> &szin, int startcsucs);

int main()
{
    ifstream f("kritikus.be5");

    if(f.fail()){
        cout << "Nincs meg a fájl!\n";
        exit(1);

    }
    int ellNum;
    int utNum;
    int start;
    int cel;

    f >> ellNum>>utNum>>start>>cel;



        int u;
        vector<vector<int> > Graph;
        stack<int> s;
        vector<int> szin;
        vector<int> kifok;
        vector<int> befok;
        vector<int> kritikuspontok;

        for (int j=0;j<ellNum;j++){

            vector<int> x;
            x.push_back(-1);
            kifok.push_back(0);
            befok.push_back(0);
            Graph.push_back(x);
            szin.push_back(0);

        }
        GraphFiller(Graph, f,kifok,befok,utNum );

        for (int i=0;i<ellNum;i++){
            if (szin[i]==0){
                MB(Graph,s,szin,i);
            }
        }
        int c;
        c=0;
        while(!s.empty()){
            u=s.top();
            s.pop();
            c=c-befok[u];
            if(c==0){
                kritikuspontok.push_back(u);
            }
            c=c+kifok[u];
        }
        cout << "**********hanydb: "<< kritikuspontok.size()-2<<"\n";
        for (int i=0;i<kritikuspontok.size();i++){
            if(kritikuspontok[i]+1!=start && kritikuspontok[i]+1!=cel){
                cout <<  kritikuspontok[i]+1<< " ";
            }
        }

    f.close();
    return 0;


}




int GraphFiller(vector<vector<int> > &Graph,ifstream &f,vector<int> &kifok, vector<int> &befok, int utNum ){
    int from, to;
    for (int i=0;i<utNum;i++){

        f >> from>>to;
        from=from-1;
        to=to-1;

        if (Graph[from][0]!=-1){
            Graph[from].push_back(to);
            kifok[from]++;
            befok[to]++;

        }
        if (Graph[from][0]==-1){
            Graph[from][0]=to;
            kifok[from]++;
            befok[to]++;
        }

    }
    return 0;
}


int MB(vector<vector<int> > &Graph,stack<int>& s,vector<int> &szin, int startcsucs)
{
        szin[startcsucs]=1;
        for (int i=0;i<Graph[startcsucs].size();i++){
            int j= Graph[startcsucs][i];
            if (szin[j]==0){
                MB(Graph,s,szin,j);
            }
		}
		szin[startcsucs]=2;
        s.push(startcsucs);


	return 0;
}

