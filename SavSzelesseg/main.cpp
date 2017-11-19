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
};

int GraphFiller(vector<vector<sav > > &Graph, ifstream &f , int kapcs);
int FeltMaxKer(vector<vector<sav> >& Graph,vector<int> &d,vector<bool> &kesz, int startcsucs,int elozo, int& n);


int main()
{
    ifstream f("net4.in");

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

        vector<int> d;
        vector<bool> kesz;

        for (int j=0;j<gepek;j++){
            vector<sav> x;
            sav s;
            s.to=-1;
            s.suly=-1;
            x.push_back(s);
            Graph.push_back(x);
            d.push_back(-1);
            kesz.push_back(false);
        }

        GraphFiller(Graph, f, kapcs);

        int n=0;
        int start=0;

        for (int z=0;z<Graph.size();z++){
            if (Graph[z].size()==1 && Graph[z][0].to!=-1 ){
                start=z;
            }
        }

        FeltMaxKer(Graph, d,kesz, start,-1, n);

        cout<<"************** \n";

        int min=d[0];
        bool osszefuggo=true;
        for (int l=0; l<d.size();l++){
            //cout<<"value, min: "<<d[l] <<"\n";
            if (min==0){
                min=d[l];
            }
            if (d[l]<min && d[l]!=0){
                min=d[l];

            }
            if (min==-1){
                osszefuggo=false;
            }

        }
        if (osszefuggo){
            cout<<"*****legkisebb d: ";
            cout<<min <<"\n";
        }else{
            cout<<"*****nem osszefuggo: 0\n";
        }


    }
    f.close();
    return 0;


}




int GraphFiller(vector<vector<sav> > &Graph,ifstream &f , int kapcs){
    int from,to,suly;

    for (int i=0;i<kapcs;i++){

        f >> from >> to >> suly;
        //cout << "from:  "<< from << ", to:  "<< to << ", suly:  "<< suly << "\n";
        from=from-1;
        to=to-1;

        if (Graph[to][0].to!=-1){
            sav s;
            s.to=from;
            s.suly=suly;
            Graph[to].push_back(s);
            //cout << "from:  "<< to << ",to:  "<< from<< ",suly:  "<< suly  << "\n";
        }
        if (Graph[from][0].to!=-1){
            sav s;
            s.to=to;
            s.suly=suly;
            Graph[from].push_back(s);
            //cout << "from:  "<< from << ",to:  "<< to<< ",suly:  "<< suly  << "\n";
        }
        if (Graph[from][0].to==-1){
            Graph[from][0].to=to;
            Graph[from][0].suly=suly;
            //cout << "from:  "<< from << ",to:  "<< to<< ",suly:  "<< suly  << "\n";

        }
        if (Graph[to][0].to==-1){
            Graph[to][0].to=from;
            Graph[to][0].suly=suly;
            //cout << "from:  "<< to << ",to:  "<< from<< ",suly:  "<< suly  << "\n";
        }
    }
    return 0;
}


int FeltMaxKer(vector<vector<sav> > &Graph,vector<int> &d,vector<bool> &kesz, int startcsucs,int elozo, int& n)
{
    //cout << "startcsucs:  "<< startcsucs << "***************************  \n";
    kesz[startcsucs]=true;
    if (Graph[startcsucs][0].to!=-1 && n<d.size()){
        int max=-1;
        int ind=0;
        for (int i=0;i<Graph[startcsucs].size();i++){
            if( Graph[startcsucs][i].suly > max && Graph[startcsucs][i].to!=elozo && !kesz[Graph[startcsucs][i].to]){
                max=Graph[startcsucs][i].suly;
                ind=i;
            }

		}
		if(n==d.size()-1){
           d[startcsucs] =0;
		}else{
            d[startcsucs]=Graph[startcsucs][ind].suly;
		}

		n++;
		//cout << "csucs:  "<< startcsucs << ", max sulya: "<< d[startcsucs] <<" , elozo: "<< elozo<< "\n";
		if(Graph[startcsucs][ind].to!=elozo){
            FeltMaxKer(Graph,d,kesz,Graph[startcsucs][ind].to,startcsucs,n);
		}

	}else{
       //cout << "startcsucs:  "<< startcsucs << "nincsenek szomszedai vagy meg van minden csucs \n";
	}
	return 0;
}

