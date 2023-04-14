#include <iostream>
using namespace std;

//vertex Node
struct Node{
	int node;
	Node* next;
};

//Linked list for Adjacency List
class linkedlist{
	Node* head;
public:
	linkedlist(){head = nullptr;}
	void insertion(int);
	void deletion(int);
	int search(int);
	void display();
	Node* getHead(){return head;}
	~linkedlist();
};

void linkedlist :: insertion(int node){
	if(!head){
		//Linked list is empty
		head = new Node;
		head->node = node;
		head->next = nullptr;
	}
	else{
		Node* newNode = new Node;
        newNode->node = node;
        newNode->next = head;
        head = newNode;
	}
}

void linkedlist :: display(){
	if(head){
		Node* p = head;
		cout<<p->node;
		p = p->next;
		while(p){
			cout<<", "<<p->node;
			p = p->next;
		}
	}
}

void linkedlist :: deletion(int node){

	//Pending: replacing key by node
	//logic of deletion pending

	if(head){
		Node* c = head;
		Node* p = nullptr;
		while(c != nullptr && node != c->node){
			p = c;
			c = c->next;
		}
		if(c){
			if(p){
				//Node in between
				p->next = c->next;
				delete c;
			}
			else{
				//Deleting head node
				head = head->next;
				delete c;
			}
		}
	}
}

int linkedlist :: search(int node){
	if(head){
		Node* p = head;
		while(p != nullptr && node != p->node){
			p = p->next;
		}
		if(p){
			return p->node;
		}
		else{
			return -1;
		}
	}
	else{
		return -1;
	}
}

linkedlist :: ~linkedlist(){
	Node* t = new Node;
	Node* p = head;
	t = nullptr;
	while(p){
		t = p;
		p = p->next;
		delete t;
	}
}



//Node structure of queue
struct NodeQ{
    int data;
    NodeQ* next;
};


//Queue to store nodes of tree
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


//Class Graph
class graph{
    linkedlist* grp;
	string* places;
	int ver;
	public:
	graph(){grp = nullptr; ver = 0; places = nullptr;}
	void insertGraph(int, int);
	void initializeGraph();
	void displayGraph();
	void storeGraph();
    void bfsTrav();
    void dfsTrav();
	void bfsGraph(int);
	void dfsGraph(int);
    int getNode(string);
	~graph();
};

void graph :: initializeGraph(){
	//Multi dimensional dynamic array
	cout<<endl;
	cout<<"Enter the no of vertices in Graph: ";
	cin>>ver;

	grp = new linkedlist[ver];

    //Allocate memory to places array
    places = new string[ver];

    //Associatte places names with integral
    cout<<"Enter list of place- "<<endl;
	string place;
    for(int i = 0; i < ver; i++){
        cout<<"Enter place: ";
        cin>>place;
        places[i] = place;
    }
}

void graph :: insertGraph(int src, int des){
	//Directed graph
	if((src>= 0 && src<ver) && (des>= 0 && des<ver)){//Valid src and des
		grp[src].insertion(des);
	}
	else{
		cout<<endl;
		cout<<"Invalid edge"<<endl;
	}
}

void graph ::storeGraph(){
	cout<<endl;
	int src=0, des=0;
	string place1, place2;
	char chc = 'y';
	while(chc == 'y' && chc != 'n'){
		cout<<"Enter source place and destination place respectively: ";
		cin>>place1>>place2;
		src = getNode(place1);
		des = getNode(place2);
		insertGraph(src, des);
		cout<<"want to continue ?(y/n): ";
		cin>>chc;
		cout<<endl;
	}
}

void graph :: bfsGraph(int v){
	Queue explore;
	int vis[ver] = {0};
	cout<<places[v];
	vis[v] = 1;
	explore.enqueue(v);

	//explore the vertices
	while(!explore.isEmpty()){
		int vertex = explore.dequeue();
		for(Node* p = grp[vertex].getHead(); p != nullptr; p = p->next){
			if(vis[p->node] == 0){
				cout<<", "<<places[p->node];
				vis[p->node] = 1;
				explore.enqueue(p->node);
			}
		}
	}
}

graph :: ~graph(){
	//Delete the array of linked list objects
	delete []grp;
    delete []places;
}

void graph ::displayGraph(){
	//Output the stored Matrix
	for(int i=0; i<ver; i++){
   		cout<<i<<": ";
   		grp[i].display();
    	cout<<endl;
	}
}

void graph :: dfsGraph(int v){
	static int vis[20] = {0};
	if(vis[v] != 1){
		cout<<places[v]<<"  ";
		vis[v] = 1;
		for(Node* p = grp[v].getHead(); p != nullptr; p = p->next)
			dfsGraph(p->node);
	}
}

int graph :: getNode(string c){
    int index = 0;
	for(int i = 0; i < ver; i++){
        if(places[i] == c){
        	index = i;
        	break;
        }
    }
    return index;
}

void graph :: bfsTrav(){
    string place;
	cout<<"Enter starting places: ";
	cin>>place;
	bfsGraph(getNode(place));
}

void graph :: dfsTrav(){
    string place;
	cout<<"Enter starting places: ";
	cin>>place;
	dfsGraph(getNode(place));
}


int main(){

	graph map;
	map.initializeGraph();
	map.storeGraph();
	cout<<endl;
	map.displayGraph();
	cout<<endl;
	cout<<"BFS of graph- "<<endl;
	map.bfsTrav();
	cout<<endl;
	cout<<"DFS of graph- "<<endl;
	map.dfsTrav();
    return 0;
}

/*
Output:
Enter the no of vertices in Graph: 5
Enter list of place-
Enter place: swarget
Enter place: narhe
Enter place: pict
Enter place: katraj
Enter place: kothrud
Enter source place and destination place respectively: swarget narhe
want to continue ?(y/n): y
Enter source place and destination place respectively: swarget pict
want to continue ?(y/n): y
Enter source place and destination place respectively: narhe katraj
want to continue ?(y/n): y
Enter source place and destination place respectively: narhe kothrud
want to continue ?(y/n): y
Enter source place and destination place respectively: pict katraj
want to continue ?(y/n): y
Enter source place and destination place respectively: katraj kothrud
want to continue ?(y/n): n
0: 2, 1
1: 4, 3
2: 3
3: 4
4:
BFS of graph-
Enter starting places: swarget
swarget, pict, narhe, katraj, kothrud
DFS of graph-
Enter starting places: pict
pict  katraj  kothrud
*/
