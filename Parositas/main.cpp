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
    while(numberOfPlayers!=0){

        vector<vector<int> > Graph;
        vector<int> szin;

        for (int j=0;j<numberOfPlayers;j++){
            szin.push_back(0);
            vector<int> x;
            x.push_back(-1);
            Graph.push_back(x);
        }
        GraphFiller(Graph, f);
        int max=0,int index=0;
        for (int i=0; i>numberOfPlayers;i++){
            if (Graph[i].size()>max){

            }
        }
        if (rooms[homeOfJerry]==1){
                cout <<"true and false";
        }else{
                bool talalkozas=false;
                bool korseta=false;
                cout << "eddig ok----------" << talalkozas;
                MB2(JerryGraph,rooms,homeOfJerry,talalkozas,korseta,homeOfJerry);
                cout << boolalpha << talalkozas<<" and "<< boolalpha << korseta ;
        }
        */
        f >> numberOfPlayers;
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


int MB2(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs,bool &talalkozas, bool &korseta,int jerry)
{
	if (!talalkozas || !korseta ){
		rooms[startcsucs]=2;
		cout << "startcsucs: "<< startcsucs << "\n";
		for (int i=0;i<Graph[startcsucs].size();i++){
            int j= Graph[startcsucs][i];
            cout << "szomszédok:  "<< j << "\n";
			if (rooms[j]==0 && j!=-1){
                cout << "----------start:  "<< j << "\n";
				MB2(Graph,rooms,j,talalkozas,korseta,jerry);
			}else if(rooms[j]==1){
			    cout << "----------találkoztak:  "<< j << "\n";
				talalkozas=true;
			}else if(rooms[j]==2){
			    cout << "----------kör:  "<< j << "\n";
			    cout << "----------startcsucs:  "<< startcsucs << "\n";
			    cout << "----------jerry:  "<< jerry << "\n";
				if ( j==jerry && startcsucs!=jerry){
					korseta=true;
				}
                cout <<"körséta: "<< boolalpha << korseta<<" \n";
			}
		}
	}
	return 0;
}
*/
