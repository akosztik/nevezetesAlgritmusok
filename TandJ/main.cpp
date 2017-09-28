#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>



using namespace std;

int GraphFiller(vector<vector<int> > &Graph, ifstream &f );
void MB(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs);
void MB2(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs,bool &talalkozas, bool &korseta,int jerry);

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
    /*
    vector<int> rooms;

    MB(TomGraph,rooms,homeOfTom);

    for (int j=0;j<roomNumbers;j++){
        rooms[j]=0;
    }
    if (rooms[homeOfJerry]==1){
			cout <<"true and false";

    }else{
			bool talalkozas=false;
			bool korseta=false;
			MB2(JerryGraph,rooms,homeOfJerry,talalkozas,korseta,homeOfJerry);
			cout << talalkozas+" and "+korseta ;

    }
    */
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
/*
void MB(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs)
{
    rooms[startcsucs]=1;
	for (int i=0;i<Graph[startcsucs].size();i++){
		if (rooms[i]==0){
			MB(Graph,rooms,i);
		}
	}
}
void MB2(vector<vector<int> > Graph,vector<int> &rooms, int startcsucs,bool &talalkozas, bool &korseta,int jerry)
{
	if (talalkozas && korseta == false ){
		rooms[startcsucs]=2;
		for (int i=0;i<Graph[startcsucs].size();i++){
			if (rooms[i]==0){
				MB2(Graph,rooms,i,talalkozas,korseta,jerry);
			}else if(rooms[i]==1){
				talalkozas=true;
			}else if(rooms[i]==2){
				if (startcsucs==jerry && i!=jerry){
					korseta=true;
				}
			}
		}
	}
}*/
