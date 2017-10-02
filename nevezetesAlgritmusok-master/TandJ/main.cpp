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
    ifstream f("input6.txt");

    if(f.fail()){
        cout << "Nincs meg a f�jl!\n";
        exit(1);

    }
    int roomNumbers, homeOfTom, homeOfJerry;
    string str;
    getline(f,str);
    istringstream is(str);
    is >> roomNumbers >> homeOfTom >> homeOfJerry;

    cout << roomNumbers;
    homeOfTom= homeOfTom-1;
    cout << homeOfTom;
    homeOfJerry= homeOfJerry-1;
    cout << homeOfJerry << "\n";
    vector<vector<int> > TomGraph;
    vector<vector<int> > JerryGraph;
    vector<int> rooms;

    for (int j=0;j<roomNumbers;j++){
        rooms.push_back(0);
        vector<int> x;
        x.push_back(-1);
        TomGraph.push_back(x);
        JerryGraph.push_back(x);
    }
    GraphFiller(TomGraph, f);
    GraphFiller(JerryGraph, f);
    f.close();

    MB(TomGraph,rooms,homeOfTom);

    if (rooms[homeOfJerry]==1){
			cout <<"true and false";

    }else{
			bool talalkozas=false;
			bool korseta=false;

			cout << "eddig ok----------" << talalkozas;
			MB2(JerryGraph,rooms,homeOfJerry,talalkozas,korseta,homeOfJerry);
			cout << boolalpha << talalkozas<<" and "<< boolalpha << korseta ;

    }

    return 0;


}




int GraphFiller(vector<vector<int> > &Graph,ifstream &f ){
    string str;
    int from,to;
    getline(f,str);
    cout << "string: " +  str + "\n";
    istringstream is(str);
    is >> from >> to;
    from=from-1;
    to=to-1;
    while( !f.fail() && from!=-2){
        cout << from << ", "<< to << "\n";
        if (Graph[from][0]==-1){
            Graph[from][0]=to;
        }else{
            Graph[from].push_back(to);
        }
            getline(f,str);
        cout << "string: " +  str + "\n";
        istringstream is(str);
        is >> from >> to;
        from=from-1;
        to=to-1;
    }
    return 0;
}

int MB(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs)
{
    rooms[startcsucs]=1;
    cout << "startcsucs: "<< startcsucs << "\n";
    cout << "size: "<< Graph[startcsucs].size() << "\n";
	for (int i=0;i<Graph[startcsucs].size();i++){
        int j= Graph[startcsucs][i];
        cout << "szomsz�dok:  "<< j << "\n";
		if (rooms[j]==0 && j!=-1){
            cout << "----------start:  "<< j << "\n";
			MB(Graph,rooms,j);
		}
	}
	cout << "szinezett? 1:  "<< rooms[startcsucs] << "\n";
	return 0;
}
int MB2(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs,bool &talalkozas, bool &korseta,int jerry)
{
	if (!talalkozas || !korseta ){
		rooms[startcsucs]=2;
		cout << "startcsucs: "<< startcsucs << "\n";
		for (int i=0;i<Graph[startcsucs].size();i++){
            int j= Graph[startcsucs][i];
            cout << "szomsz�dok:  "<< j << "\n";
			if (rooms[j]==0 && j!=-1){
                cout << "----------start:  "<< j << "\n";
				MB2(Graph,rooms,j,talalkozas,korseta,jerry);
			}else if(rooms[j]==1){
			    cout << "----------tal�lkoztak:  "<< j << "\n";
				talalkozas=true;
			}else if(rooms[j]==2){
			    cout << "----------k�r:  "<< j << "\n";
			    cout << "----------startcsucs:  "<< startcsucs << "\n";
			    cout << "----------jerry:  "<< jerry << "\n";
				if ( j==jerry && startcsucs!=jerry){
					korseta=true;
				}
                cout <<"k�rs�ta: "<< boolalpha << korseta<<" \n";
			}
		}
	}
	return 0;
}
