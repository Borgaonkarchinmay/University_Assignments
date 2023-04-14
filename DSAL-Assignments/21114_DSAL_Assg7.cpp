#include<iostream>
using namespace std;
# define infinity 2147483647;

class graph{
    int** grp;
    int ver;
    string* cities;
public:
    graph();
    graph(int);
    void initializeGraph();
    void storeGraph();
    void insertGraph(int, int, int);
    void prims(int);
    void minCost(int);
    int getNode(string);
    void display();
    ~graph();

};

graph :: graph(){
    grp = nullptr;
    cities = nullptr;
    ver = 0;
}

graph :: graph(int v){
	grp = nullptr;
	cities = nullptr;
	ver = v;

	//Allocate memory to graph
	grp = new int*[ver];
    for(int i = 0; i < ver; i++){
    	grp[i] = new int[ver];
    }

    //Allocate memory to cities array
    cities = new string[ver];

    //Initialize all values to infinity
    for(int i = 0; i < ver; i++){
    	for(int j = 0; j < ver; j++){
    		grp[i][j] = infinity;
    	}
    }
}

void graph :: storeGraph(){
    int v1, v2, cost = 0;
    string city1, city2;
    char choice = 'y';
    while(choice == 'y' && choice != 'n'){
        cout<<"Insert pair of cities:  ";
        cin>>city1>>city2;
        cout<<"Enter cost of connection: ";
        cin>>cost;
        v1 = getNode(city1);
        v2 = getNode(city2);
        insertGraph(v1, v2, cost);
        insertGraph(v2, v1, cost);
        cout<<"Do you want to continue ('y'/'n')? : ";
        cin>>choice;
        cout<<endl;
    }
}

void graph :: insertGraph(int v1, int v2, int c){
    if((v1 >= 0 && v1 < ver) && (v2 >= 0 && v2 < ver)){
        grp[v1][v2] = c;
    }
}

void graph :: initializeGraph(){
    cout<<endl;
    cout<<"Number of cities to be connected: ";
    cin>>ver;
    string city;

    //Allocate memory to graph
    grp = new int*[ver];
    for(int i = 0; i < ver; i++){
        grp[i] = new int[ver];
    }

    //Allocate memory to cities array
    cities = new string[ver];

    //Initialize all values to infinity
    for(int i = 0; i < ver; i++){
        for(int j = 0; j < ver; j++){
            grp[i][j] = infinity;
        }
    }

    //Associatte city names with integral
    cout<<"Enter list of cities- "<<endl;
    for(int i = 0; i < ver; i++){
        cout<<"Enter city: ";
        cin>>city;
        cities[i] = city;
    }
}

void graph :: display(){
    for(int i = 0; i < ver; i++){
        for(int j = 0; j < ver; j++){
            if(grp[i][j] == 2147483647){
                cout<<"- ";
            }
            else{
                cout<<grp[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void graph :: prims(int olde){
    //Initialization

    int near[ver]; //near array
    int mst[2][ver - 1]; //result minimum spanning tree
    int newe = 0, min_cost = 0;
    graph minGrp(ver);

    //find the closest vertex to given vertex (old)
    for(int i = 0; i < ver; i++){
        if(grp[olde][i] < grp[olde][newe]){
            newe = i;
        }
    }

    //Add first edge in mst
    mst[0][0] = newe;
    mst[1][0] = olde;
    min_cost = grp[mst[0][0]][mst[1][0]];
    minGrp.insertGraph(olde, newe, grp[mst[0][0]][mst[1][0]]);
    minGrp.insertGraph(newe, olde, grp[mst[0][0]][mst[1][0]]);
    near[newe] = near[olde] = -1;


    //Manipulate near array
    for(int i = 0; i < ver; i++){
        if(near[i] != -1){
            if(grp[i][olde] < grp[i][newe])
                near[i] = olde;
            else if(grp[i][olde] > grp[i][newe])
                near[i] = newe;
            else
                near[i] = newe;
        }
    }
    //----------------------------------

    //Repeating

    for(int count = 1; count < ver-1; count++){
        //Find minimum edge from near array
        int newe = 0;
        int cost = infinity;
        for(int i = 0; i < ver; i++){
            if((near[i] != -1) && (grp[i][near[i]] < cost)){
                newe = i;
                cost = grp[i][near[i]];
            }
        }

        //Add new edge
        mst[0][count] = newe;
        mst[1][count] = near[newe];
        min_cost += grp[mst[0][count]][mst[1][count]];
        minGrp.insertGraph(newe, near[newe], cost);
        minGrp.insertGraph(near[newe], newe, cost);
        near[newe] = -1;

        //Manipulate near array
        for(int i = 0; i < ver; i++){
            if(near[i] != -1){
                if(grp[i][near[i]] < grp[i][newe])
                    continue;
                else if(grp[i][near[i]] > grp[i][newe])
                    near[i] = newe;
                else
                    near[i] = newe;
            }
        }
    }

    //Display found tree
    cout<<endl;
    cout<<"Minimum cost tree is- "<<endl;
    minGrp.display();


    cout<<endl;
    cout<<"Cities to be connected will be-"<<endl;
    for(int i = 0; i < ver - 1; i++){
        cout<<cities[mst[0][i]]<<" : "<<cities[mst[1][i]]<<endl;
    }
    cout<<"Minimum cost of connection is: "<<min_cost<<endl;
}

int graph :: getNode(string c){
    int index = 0;
	for(int i = 0; i < ver; i++){
        if(cities[i] == c){
        	index = i;
        	break;
        }
    }
    return index;
}

graph :: ~graph(){
    delete []cities;

    //Delete inner arrays
    for(int i = 0; i < ver; i++){
        delete []grp[i];
    }
    //Delete outter arrays
    delete []grp;
}

int main(){
    graph o1;
    o1.initializeGraph();
    cout<<endl;
    o1.storeGraph();
    cout<<endl;
    o1.display();
    cout<<"Minimum spanning tree is- "<<endl;
    o1.prims(0);
    return 0;
}
/*
Number of cities to be connected: 5
Enter list of cities- 
Enter city: akola
Enter city: latur
Enter city: jalgaon
Enter city: pune
Enter city: mumbai

Insert pair of cities:  akola latur
Enter cost of connection: 18
Do you want to continue ('y'/'n')? : y

Insert pair of cities:  akola jalgaon
Enter cost of connection: 1
Do you want to continue ('y'/'n')? : y

Insert pair of cities:  latur pune
Enter cost of connection: 7
Do you want to continue ('y'/'n')? : y

Insert pair of cities:  latur mumbai
Enter cost of connection: 4
Do you want to continue ('y'/'n')? : y

Insert pair of cities:  jalgaon pune
Enter cost of connection: 26
Do you want to continue ('y'/'n')? : y

Insert pair of cities:  pune mumbai
Enter cost of connection: 15
Do you want to continue ('y'/'n')? : n


- 18 1 - - 
18 - - 7 4 
1 - - 26 - 
- 7 26 - 15 
- 4 - 15 - 
Minimum spanning tree is- 

Minimum cost tree is- 
- 18 1 - - 
18 - - 7 4 
1 - - - - 
- 7 - - - 
- 4 - - - 

Cities to be connected will be-
jalgaon : akola
latur : akola
mumbai : latur
pune : latur
Minimum cost of connection is: 30

*/
