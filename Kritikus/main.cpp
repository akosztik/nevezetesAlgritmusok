#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>



using namespace std;

int GraphFiller(vector<vector<int> > &Graph, ifstream &f , int utNum);
int MB(vector<vector<int> >& Graph,stack<int>& s,vector<int> &szin, int startcsucs);
int TopRend(vector<vector<int> >& Graph,stack<int>& s );

int main()
{
    ifstream f("kritikus.be1");

    if(f.fail()){
        cout << "Nincs meg a fájl!\n";
        exit(1);

    }
    int ellNum;
    int utNum;
    int start;
    int cel;

    f >> ellNum>>utNum>>start>>cel;




        vector<vector<int> > Graph;
        stack<int> s;
        vector<int> szin;

        for (int j=0;j<ellNum;j++){

            vector<int> x;
            x.push_back(-1);
            Graph.push_back(x);
        }
        GraphFiller(Graph, f,utNum );
        TopRend(Graph,s);
        int c;
        c=0;
        while(!s.empty()){

        }


    f.close();
    return 0;


}




int GraphFiller(vector<vector<int> > &Graph,ifstream &f, int utNum ){
    int from, to;
    for (int i=0;i<utNum;i++){

        f >> from>>to;
        from=from-1;
        to=to-1;

        cout << from << ", "<< to << "\n";

        if (Graph[from][0]!=-1){
            Graph[from].push_back(to);

        }
        if (Graph[from][0]==-1){
            Graph[from][0]=to;
        }

    }
    return 0;
}
int TopRend(vector<vector<int> >& Graph,stack<int>& s ){

}

int MB(vector<vector<int> > &Graph,stack<int>& s,vector<int> &szin, int startcsucs)
{
        //cout << "startcsucs: "<< startcsucs << "\n";
        for (int i=0;i<Graph[startcsucs].size();i++){
            int j= Graph[startcsucs][i];
            //cout << "szomszédok:  "<< j << "\n";
            if (j!=startcsucs && j!=-1){
               if (  szin[j]==0 ){
                    //cout << "----------nem színezett/start:  "<< j << "\n";
                    if (szin[startcsucs]==1){
                        szin[j]=2;
                    }else{
                        szin[j]=1;
                    }
                    MB(Graph,szin,j,paros);
                }else if( szin[j]==szin[startcsucs]){
                    /*cout << "----------szinezett:  "<< j << "\n";
                    cout << "----------startcsucs:  "<< szin[startcsucs] << "\n";
                    cout << "----------szomszéd:  "<< szin[j] << "\n";

                    paros=false;
                }
            }

		}



	return 0;
}

