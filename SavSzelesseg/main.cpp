#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <utility>      // std::pair


using namespace std;



struct sav{
        int to;
        int suly;
        sav(int x, int y){
            this.to=x;
            this.suly=y;
        }
};

int GraphFiller(vector<vector<sav > > &Graph, ifstream &f , int kapcs);
int MB(vector<vector<int> >& Graph,vector<int> &szin, int startcsucs,bool &paros);


int main()
{
    ifstream f("net.in");

    if(f.fail()){
        cout << "Nincs meg a fájl!\n";
        exit(1);

    }
    int numberOfTasks;
    f >> numberOfTasks;

    for (int i=0;i<numberOfTasks;i++){

        cout<<"\n**************"<<i+1<<". eset: \n";

        vector<vector<sav> > Graph;

        //gépek és kapcsolatok számának beolvasása:

        int gepek, kapcs;
        f >> gepek >> kapcs;

        vector<bool> kesz;

        for (int j=0;j<gepek;j++){
            vector<sav> x;
            sav s = new sav();
            s.to=-1;
            s.suly=-1;
            x.push_back(s);
            Graph.push_back(x);
            kesz.push_back(false);
        }

        GraphFiller(Graph, f, kapcs);
        /*
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
*/
    }
    f.close();
    return 0;


}




int GraphFiller(vector<vector<sav> > &Graph,ifstream &f , int kapcs){
    int from,to,suly;

    for (int i=0;i<kapcs;i++){

        f >> from >> to >> suly;
        cout << "from:  "<< from << ", to:  "<< to << ", suly:  "<< suly << "\n";
        from=from-1;
        to=to-1;

        if (Graph[to][0].to!=-1){
            sav s=new sav();
            sav.to=from;
            sav=suly=suly;
            Graph[to].push_back(sav);
            cout << "from:  "<< to << ",to:  "<< from<< ",suly:  "<< suly  << "\n";
        }
        if (Graph[from][0].to!=-1){
            sav s=new sav();
            sav.to=to;
            sav=suly=suly;
            Graph[from].push_back(s);
            cout << "from:  "<< from << ",to:  "<< to<< ",suly:  "<< suly  << "\n";
        }
        if (Graph[from][0].to==-1){
            sav.to=to;
            sav=suly=suly;
            cout << "from:  "<< from << ",to:  "<< to<< ",suly:  "<< suly  << "\n";

        }
        if (Graph[to][0].to==-1){
            sav.to=from;
            sav=suly=suly;
            cout << "from:  "<< to << ",to:  "<< from<< ",suly:  "<< suly  << "\n";
        }
    }
    return 0;
}

/*
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
                    cout << "----------szinezett:  "<< j << "\n";
                    cout << "----------startcsucs:  "<< szin[startcsucs] << "\n";
                    cout << "----------szomszéd:  "<< szin[j] << "\n";

                    paros=false;
                }
            }

		}



	return 0;
}
*/
