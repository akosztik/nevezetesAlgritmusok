#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>



using namespace std;

int GraphFiller(vector<vector<int> > &Graph, ifstream &f );
int MB(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs);
int MB2(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs,bool &talalkozas, bool &korseta,int jerry);

int main()
{
    ifstream f("input0.txt");

    if(f.fail()){
        cout << "Nincs meg a fájl!\n";
        exit(1);

    }
    int numberOfPlayers;
    f >> numberOfPlayers;
    cout << "numberOfPlayers----------" << numberOfPlayers<<"\n";
    int task=1;
    while(numberOfPlayers!=0){

        cout<<task<<"\n. feladat: \n";

        vector<vector<int> > Graph;
        vector<int> szin;

        for (int j=0;j<numberOfPlayers;j++){
            szin.push_back(0);
            vector<int> x;
            x.push_back(-1);
            Graph.push_back(x);
        }
        GraphFiller(Graph, f);
        int max=0;
        int index=0;
        for (int i=0; i>numberOfPlayers;i++){
            if (Graph[i].size()>max){
                max=Graph[i].size();
                index=i;
            }
        }

        bool paros=true;
        szin[max]=1;

        MB(vector<vector<int> > Graph,vector<int> &szin, int max,bool &paros);
        if (!paros){
           cout<<"nem páros. \n";
        }else{
            vector<int> A,B;

            for (int i=0; i>numberOfPlayers;i++){
                if (szin[i]==0){
                    A.push_back(i);
                }else{
                    B.push_back(i);
                }
            }
            sort(A.end(),A.begin());
            sort(B.end(),B.begin());
            cout<<"A: \n";
            for (int i=0; i>A.size();i++){
                cout<<A[i]<<" ,";
            }
            cout<<"\nB: \n";
            for (int i=0; i>B.size();i++){
                cout<<B[i]<<" ,";
            }
        }



        f >> numberOfPlayers;
        task++;
        cout << "numberOfPlayers----------" << numberOfPlayers<< "\n";
    }
    f.close();
    return 0;


}




int GraphFiller(vector<vector<int> > &Graph,ifstream &f ){
    int from, to;
    f >> from >> to;
    cout << "from:  "<< from << ", to:  "<< to << "\n";
    from=from-1;
    to=to-1;
    while(from!=-1 && to!=-1){
        cout << from << ", "<< to << "\n";
        if (Graph[from][0]==-1){
            Graph[from][0]=to;
        }else if (Graph[to][0]==-1){
            Graph[from][0]=to;
        }else if (Graph[to][0]!=-1){
            Graph[to].push_back(from);
        }else if (Graph[from][0]!=-1){
            Graph[from].push_back(to);
        }
        f >> from >> to;
        cout << "from:  "<< from << ", to:  "<< to << "\n";
        from=from-1;
        to=to-1;
    }
    return 0;
}


int MB2(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs,bool &paros)
{

    while(paros){
		cout << "startcsucs: "<< startcsucs << "\n";
		for (int i=0;i<Graph[startcsucs].size();i++){
            int j= Graph[startcsucs][i];
            cout << "szomszédok:  "<< j << "\n";
			if (szin[j]==0 && j!=-1){
                cout << "----------nem színezett/start:  "<< j << "\n";
                if (szin[startcsucs==0]){
                    szin[j]=1;
                }else{
                    szin[j]=0;
                }
				MB2(Graph,szin,j,paros);
			}else if(szin[j]!=0){
			    cout << "----------kör:  "<< j << "\n";
			    cout << "----------startcsucs:  "<< szin[startcsucs] << "\n";
			    cout << "----------szomszéd:  "<< szin[j] << "\n";
			    if (szin[j]==szin[startcsucs]){
                    paros=false;
			    }
			}
		}
    }
	return 0;
}
*/
