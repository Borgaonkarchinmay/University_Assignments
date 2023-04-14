#include<iostream>
using namespace std;

struct NodeQ{
    int data;
    NodeQ* next;
};


//Queue to store nodes of grpah
class Queue{
	NodeQ* head;
	NodeQ* tail;
	public:
		Queue();
		~Queue();
        NodeQ* getHead();
		void display();
		void enqueue(int);
		int dequeue();
		int length();
        bool isEmpty();
        bool isPresent(int);
};

Queue :: Queue(){
	head = NULL;
	tail = NULL;
}

void Queue :: enqueue(int item){
	//Check if Queue is empty
	//Queue is empty only if head pointer is NULL
	if(head == NULL){
		head = new NodeQ;
		head->data = item;
		head->next = NULL;
		tail = head;
	}

	//If Queue is Non-Empty
	else{
		NodeQ* newNode = new NodeQ;
		newNode->data = item;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

int Queue :: dequeue(){
	//Check if Queue is Empty
	if(head == NULL){
		return -1;
	}
	//If Queue is Non-Empty
	else{
		//If there are more than one elements in Queue
		if(head != tail){
            int data = head->data;
			NodeQ* temp = new NodeQ;
			temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
            return data;
		}

		//If only one element is there is Queue
		else{
            int data = head->data;
			delete head;
            head = NULL;
			tail = NULL;
            return data;
		}
	}
}

int Queue :: length(){
	NodeQ* p = head;
	int len = 0;
	while(p){
		len++;
		p = p->next;
	}
	return len;
}

void Queue :: display(){

	cout<<endl;
	NodeQ* ptr = head;
	cout<<ptr->data;
	while(ptr->next){
		ptr = ptr->next;
		cout<<", ";
		cout<<ptr->data;
	}
	cout<<endl;
}

bool Queue :: isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool Queue :: isPresent(int data){
    NodeQ* p = head;
    while(p){
        if(p->data == data)
            return true;
        p = p->next;
    }
    return false;
}

NodeQ* Queue :: getHead(){
    return head;
}

Queue :: ~Queue(){
	NodeQ* ptr = head;
	NodeQ* temp = new NodeQ;
	ptr = head;
	while(ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		temp->next = NULL;
		delete temp;
	}
}


//Graph
class graph{
    int** grp;
    int ver;
public:
    graph();
    void initializeGraph();
    void storeGraph();
    void insertGraph(int, int);
    void topoSort();
    int inDeg(int);
    void display();
    ~graph();
    
};

graph :: graph(){
    grp = nullptr;
    ver = 0;
}

void graph :: storeGraph(){
    int src, des;
    char choice = 'y';
    while(choice == 'y' && choice != 'n'){
        cout<<"Enter source and destination nodes: ";
        cin>>src>>des;
        insertGraph(src, des);
        cout<<"Do you want to continue ('y'/'n')? : ";
        cin>>choice;
        cout<<endl;
    }
}

void graph :: insertGraph(int v1, int v2){
    if((v1 >= 0 && v1 < ver) && (v2 >= 0 && v2 < ver)){
        grp[v1][v2] = 1;
    }
}

void graph :: initializeGraph(){
    cout<<endl;
    cout<<"Number of nodes to be connected: ";
    cin>>ver;

    //Allocate memory to graph
    grp = new int*[ver];
    for(int i = 0; i < ver; i++){
        grp[i] = new int[ver];
    }

    //Initialize all values to infinity
    for(int i = 0; i < ver; i++){
        for(int j = 0; j < ver; j++){
            grp[i][j] = 0;
        }   
    }
}

int graph :: inDeg(int node){
    int indeg = 0;
    for(int i = 0; i < ver; i++){
        if(grp[i][node] == 1)
            indeg++;
    }
    return indeg;
}

void graph :: topoSort(){
    //Set in-degree array
    int indeg[ver];
    int node = 0;
    Queue temp;
    for(int i = 0; i < ver; i++){
        indeg[i] = inDeg(i);
        if(indeg[i] == 0)
            temp.enqueue(i);
    }

    while(!temp.isEmpty()){
        //Dequeue from Queue
        node = temp.dequeue();
        
            cout<<node<<", ";

            //Update inDeg array
            for(int i = 0; i < ver; i++){
                if(grp[node][i] == 1){
                    indeg[i] -= 1;
                    grp[node][i] = 0;
                if(indeg[i] == 0)
                    temp.enqueue(i);
		}
            }
        
    }
}   

void graph :: display(){
    for(int i = 0; i < ver; i++){
        for(int j = 0; j < ver; j++){
            cout<<grp[i][j]<<" ";
        }
        cout<<endl;   
    }
}

graph :: ~graph(){
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
    cout<<"Topological Sort: ";
    o1.topoSort();
    return 0;
}
