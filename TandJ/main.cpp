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

    GraphFiller(TomGraph, f);
    GraphFiller(JerryGraph, f);

    f.close();

    vector<int> rooms;

    for (int j=0;j<roomNumbers;j++){
        rooms.push_back(0);
    }

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
    getline(f,str);
    int from,to;
    cout << "string: " +  str + "\n";
    istringstream is(str);
    is >> from >> to;
    from=from-1;
    to=to-1;
    cout <<  from << " " << to << "\n";
    int var=0;

    while( !f.fail() && var!=-2){
        cout<< var << " \n";
        vector<int> x;
        while(!f.fail() && var==from ){
                cout << from << ", "<< to << "\n";
                x.push_back(to);
                var=from;
                getline(f,str);
                cout << "loop-string: "+  str + "\n";
                istringstream ls(str);
                ls >> from >> to;
                from=from-1;
                to=to-1;
                cout << "loop-from: "<< from << "\n";

        }
        Graph.push_back(x);
        cout<< "vector eleje: " << x[0];
        var=from;
        cout << "hejj: "<<var <<"\n";




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
        cout << "szomszédok:  "<< j << "\n";
		if (rooms[j]==0){
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
            cout << "szomszédok:  "<< j << "\n";
			if (rooms[j]==0){
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
			}
		}
	}
	return 0;
}
