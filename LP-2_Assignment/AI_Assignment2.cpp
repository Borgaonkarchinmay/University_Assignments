/*
 A star algorithm for state space search
 Its a informed search technique
 This code solves the A star graph problem
 The graph can be : Directed or Undirected
*/


/*
Graph is represented as vector<vector<pair<int, int>>>

e.g.        1 --- 2
            |     |
            |     |
            3 --- 4

Will be represented as

    1 : <2, 4>, <3, 3>
    2 : <1, 4>, <4, 5>
    3 : <1, 3>, <4, 12>
    4 : <3, 12>, <2, 5>

    Here cost of 1 -- 2 edge is 4 and
         cost of 1 -- 3 edge is 3 

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Its a struct involving required parameters
struct openListNode{
    // required for computing minimum path 
    int f;
    int g;

    int label; // required for both identifying and tracing back the traversed path

    //required for tracing back the traversed nodes to identify the path taken to reach the goal
    //in minimum cost
    int id;
    int parent;
};

class Graph{
    vector< vector< pair<int, int> > > grp;
    vector<int> hueristic;
    int nodes;
    int edges;
    public:
    Graph(){ nodes = 0;}
    Graph(int, int);
    void initGraph();
    void drawGraph();
    int AStar(int, int);
};

Graph :: Graph(int n, int e){
    nodes = n;
    edges = e;

    for(int i = 0; i < n; i++){
        vector< pair<int, int> > temp;
        grp.emplace_back(temp);
    }
}

void Graph :: initGraph(){
    int n1 = 0, n2 = 0, cost = 0;
    char isDirected = 'n';
    cout<<"Is graph directed: (y/n ?)";
    cin>>isDirected;

    for(int i = 0; i < edges; i++){
        if(isDirected == 'y')
            cout<<"enter src des ('0 indexed') cost: ";
        else
            cout<<"enter n1 n2 ('0 indexed') cost: ";
        
        cin>>n1>>n2>>cost;
        pair<int, int> pr;
        pr.first = n2;
        pr.second = cost;
        grp[n1].emplace_back(pr);

        if(isDirected == 'n'){
            pr.first = n1;
            grp[n2].emplace_back(pr);
        }
    }

    int val = 0;
    for(int i = 0; i < nodes; i++){
        cout<<"enter h("<<i<<"): ";
        cin>>val;
        hueristic.emplace_back(val);
    }
}

void Graph :: drawGraph(){
    for(int i = 0; i < nodes; i++){
        cout<<i<<" :";
        for(auto n : grp[i])
            cout<<" <"<<n.first<<", "<<n.second<<">";
        cout<<endl;
    }
    
    for(int i = 0; i < nodes; i++){
        cout<<i<<": "<<hueristic[i]<<endl;
    }
}

int Graph :: AStar(int startNode, int goalNode){
    auto cmp = [](openListNode n1, openListNode n2){
        return n1.f < n2.f;
    };

    vector<openListNode> openList; // stores all the nodes that are visited but are yet to be explored/expanded


    vector<openListNode> traversedNodeList; // stores all the nodes which are traversed 
                                            // while searching for the minimum cost

    /*
        All openListNodes are tagged by ID
        and are linked by parent relationship
        to trace back the same traversed path which achieved the minimum cost
    */
    
    vector<int> closeList(nodes, 0); // Nodes which are visited and also completely expanded/explored

    int idCounter = 1;
    int minimumCost = 0;
    openListNode currentNode;

    currentNode.label = startNode;
    currentNode.g = 0;
    currentNode.f = hueristic[currentNode.label];
    currentNode.id = idCounter; // set id to visited node
    idCounter++;
    currentNode.parent = -1; // mark the parent of visited node

    openList.emplace_back(currentNode);

    while(openList.size() > 0){

        currentNode = openList[0];
        traversedNodeList.emplace_back(currentNode); // track traversed nodes
        openList.erase(openList.begin());

        if(currentNode.label != goalNode){

            for(auto pr : grp[currentNode.label]){
                
                if(closeList[pr.first] != 1){

                    openListNode newNode;
                    newNode.label = pr.first;
                    newNode.g = currentNode.g + pr.second;
                    newNode.f = newNode.g + hueristic[newNode.label];

                    newNode.id = idCounter; // assign ID to the node
                    idCounter++;
                    newNode.parent = currentNode.id; // track its parent

                    openList.emplace_back(newNode); 
                }
            }

            closeList[currentNode.label] = 1;
            sort(openList.begin(), openList.end(), cmp);
        }

        else{
            minimumCost = currentNode.f;

            // Trace back the traversed route to reach the goal in minimum cost
            string path = to_string(currentNode.label);
            int searchId = currentNode.parent; // Set the node ID to be searched
            
            while(searchId != -1){
                
                for(auto node : traversedNodeList){
                    if(node.id == searchId){
                        path = to_string(node.label) + " -> " + path; // trace the path
                        searchId = node.parent; // Search the parent of current Node
                    }
                }

            }

            cout<<"Minimum cost path: "<<path<<endl;
            return minimumCost;
            break;
        }
    }
    return -1;    
}

int main(){
    int nodes = 0, edges = 0;
    cout<<"Enter nodes and edges: ";
    cin>>nodes>>edges;
    Graph g1(nodes, edges);
    g1.initGraph();
    cout<<endl;
    int startNode = 0, goalNode = 0;
    cout<<"Enter start and goal node: ";
    cin>>startNode>>goalNode; 
    int ans = g1.AStar(startNode, goalNode);

    if(ans != -1){
        cout<<"Minimum cost: "<<ans;
    }
    else{
        cout<<"No path exists"<<endl;
    }
    
    return 0;
}

/*

OUTPUT:

Enter nodes and edges: 6 8
Is graph directed: (y/n ?)y
enter src des ('0 indexed') cost: 0 1 1
enter src des ('0 indexed') cost: 1 2 2
enter src des ('0 indexed') cost: 1 3 1
enter src des ('0 indexed') cost: 0 5 10
enter src des ('0 indexed') cost: 2 4 5
enter src des ('0 indexed') cost: 3 4 3
enter src des ('0 indexed') cost: 3 5 4
enter src des ('0 indexed') cost: 4 5 2
enter h(0): 5  
enter h(1): 3
enter h(2): 4
enter h(3): 2
enter h(4): 6
enter h(5): 0

Enter start and goal node: 0 5
Minimum cost path: 0 -> 1 -> 3 -> 5
Minimum cost: 6

*/
