#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>



using namespace std;

int GraphFiller(vector<vector<int> > &Graph, ifstream &f );
int MB(vector<vector<int> >& Graph,vector<int> &szin, int startcsucs,bool &paros);


int main()
{
    ifstream f("input5.txt");

    if(f.fail()){
        cout << "Nincs meg a fájl!\n";
        exit(1);

    }
    int numberOfPlayers;
    f >> numberOfPlayers;
    //cout << "numberOfPlayers----------" << numberOfPlayers<<"\n";
    int task=1;
    while(numberOfPlayers!=0){

        cout<<"\n**************"<<task<<". feladat: \n";

        vector<vector<int> > Graph;
        vector<int> szin;

        for (int j=0;j<numberOfPlayers;j++){
            szin.push_back(0);
            vector<int> x;
            x.push_back(-1);
            Graph.push_back(x);
        }
        GraphFiller(Graph, f);


        bool paros=true;
        for (int i=0; i<szin.size();i++){
                if (szin[i]==0 && paros){
                    szin[i]=1;
                    MB(Graph,szin,i,paros);
                }
        }

        if (!paros){
           cout<<"\n**************nem paros. \n";
        }else{
            vector<int> A,B;

            for (int i=0; i<szin.size();i++){
                if (szin[i]==1){
                    A.push_back(i+1);

                }else if(szin[i]==2){
                    B.push_back(i+1);

                }
            }
            cout<<"************** \n";
            cout<<"*****A: ";
            for (int i=0; i<A.size();i++){
                   cout<<A[i]<<" ,";
            }
            cout<<"\n*****B: ";
            for (int i=0; i<B.size();i++){
                cout<<B[i]<<" ,";
            }
            cout<<"\n************** \n";
        }



        f >> numberOfPlayers;
        task++;
      //  cout << "\nnumberOfPlayers----------" << numberOfPlayers<< "\n";
    }
    f.close();
    return 0;


}




int GraphFiller(vector<vector<int> > &Graph,ifstream &f ){
    int from, to;
    f >> from >> to;
    from=from-1;
    to=to-1;
    while(from!=-1 && to!=-1){
        //cout << from << ", "<< to << "\n";
        if (Graph[to][0]!=-1){
            Graph[to].push_back(from);
            //cout << "from:  "<< from<< "\n";
        }
        if (Graph[from][0]!=-1){
            Graph[from].push_back(to);
            //cout << "to:  "<< to<< "\n";
        }
        if (Graph[from][0]==-1){
            Graph[from][0]=to;
            //cout << "to:  "<< to<< "\n";

        }
        if (Graph[to][0]==-1){
            Graph[to][0]=from;
            //cout << "from:  "<< from<< "\n";
        }
        f >> from >> to;
        //cout << "from:  "<< from << ", to:  "<< to << "\n";
        from=from-1;
        to=to-1;
    }
    return 0;
}


int MB(vector<vector<int> > &Graph,vector<int> &szin, int startcsucs,bool &paros)
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
                    */
                    paros=false;
                }
            }

		}



	return 0;
}

