#include<iostream>
using namespace std;

//Node structure for tree
struct NodeT{
    NodeT* lchild;
    int data;
    NodeT* rchild;
};

//Node structure of queue
struct NodeQ{
    NodeT* data;
    NodeQ* next;
};

//Node structure for Stack
struct Node{
	NodeT* data;
	Node* next;	
};




//Stack
class Stack{
	Node* top;
	public:
		Stack();
		~Stack();
		bool isempty();
		void push(NodeT*);
        NodeT* TOS();
		NodeT* pop();
		void display();
};

Stack :: Stack(){
	top = NULL;
}

bool Stack :: isempty(){
	if(top == NULL){
		return true;
	}
	else{
		return false;
	}
}

void Stack :: push(NodeT* node){
	if(top == NULL){
		top = new Node;
		top->data = node;
		top->next = NULL;
	}
	
	else{
		Node* newNode = new Node;
		newNode->data = node;
		newNode->next = top;
		top = newNode;
	}
}

NodeT* Stack :: pop(){
	if(top == NULL){
		return NULL;
	}
	else{
		Node* temp = new Node;
		temp = top;
        NodeT* node = top->data;
		top = top->next;
		temp->next = NULL;
		delete temp;
        return node;
	}
}

void Stack :: display(){
	cout<<endl;
	cout<<"Below is the stored Stack in the heap memory-"<<endl;
	Node* ptr = new Node;
	ptr = top;
	cout<<"Address of 'TOP of STACK' is: "<<ptr<<endl;
	while(ptr != NULL){
		cout<<"Address: "<<ptr<<" -> Data: "<<ptr->data<<endl;
		ptr = ptr->next;
	}
}

NodeT* Stack :: TOS(){
    if(top == NULL){
        return NULL;
    }
    else{
        return top->data;
    }
}

Stack :: ~Stack(){
	Node* ptr = new Node;
	Node* temp = new Node;
	ptr = top;
	while(ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		temp->next = NULL;
		delete temp;
	}
}




//Queue to store nodes of tree
class Queue{
	NodeQ* head;
	NodeQ* tail;
	public:
		Queue();
		~Queue();
        NodeQ* getHead();
		void display();
		void insertion(NodeT*);
		NodeT* deletion();
        bool isEmpty();
};

Queue :: Queue(){
	head = NULL;
	tail = NULL;
}

void Queue :: insertion(NodeT* item){
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

NodeT* Queue :: deletion(){
	//Check if Queue is Empty
	if(head == NULL){
		return NULL;
	}
	//If Queue is Non-Empty
	else{
		//If there are more than one elements in Queue
		if(head != tail){
            NodeT* node = head->data;
			NodeQ* temp = new NodeQ;
			temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
            return node;
		}
		
		//If only one element is there is Queue
		else{
            NodeT* node = head->data;
			delete head;
            head = NULL;
			tail = NULL;
            return node;
		}
	}
}

void Queue :: display(){
	
	cout<<endl;
	cout<<"Stored Queue is: "<<endl;
	NodeQ* ptr = head;
	cout<<"Head: "<<ptr->data;
	while(ptr->next != NULL){
		ptr = ptr->next;
		cout<<" <- ";
		cout<<ptr->data;
	}
	cout<<":Tail"<<endl;
}

bool Queue :: isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
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




//Tree
class Tree{
    NodeT* root;
    public:
    Tree();
    void create();
    void PreOrderItr();
    void InOrderItr();
    void PostOrderItr();
    void preorderRec(NodeT*);
    void inorderRec(NodeT*);
    void postorderRec(NodeT*);
    int count_internalNode(NodeT*);
    int count_leafNode(NodeT*);
    int height(NodeT*);
    NodeT* getRoot();
    NodeT* copy(NodeT*);
    void mirrorTree(NodeT*);
    void operator = (Tree);
    void Delete(NodeT*);
    ~Tree();
};

Tree :: Tree(){
    root = NULL;
}

NodeT* Tree :: getRoot(){
    return root;
}

NodeT* Tree :: copy(NodeT* ptr){
    if(!ptr)
        return NULL;
    else{
        NodeT* temp = new NodeT;
        temp->data = ptr->data;
        temp->lchild = copy(ptr->lchild);
        temp->rchild = copy(ptr->rchild);
        return temp;
    }
}

void Tree :: create(){
    Queue temp;
    int data;
    cout<<endl;
    cout<<"Enter data of root node: ";
    cin>>data;
    root = new NodeT;
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    temp.insertion(root);
    
    NodeQ* ptr = temp.getHead();
    while(ptr != NULL){
        cout<<endl;
        cout<<"Enter lchild data of '"<<ptr->data->data<<"' : ";
        cin>>data;
        if(data!=-1){
            NodeT* newNode= new NodeT;
            newNode->data = data;
            newNode->lchild=NULL;
            newNode->rchild=NULL;
            ptr->data->lchild = newNode;
            temp.insertion(newNode);
        }
        cout<<endl;
        cout<<"Enter rchild data of '"<<ptr->data->data<<"' : ";
        cin>>data;
        if(data!=-1){
        NodeT* newNode= new NodeT;
        newNode->data = data;
        newNode->lchild=NULL;
        newNode->rchild=NULL;
        ptr->data->rchild = newNode;
        temp.insertion(newNode);
        }
        ptr = ptr->next;
    }    
}

void Tree :: preorderRec(NodeT* ptr){
    if(ptr!=NULL){
        cout<<ptr->data<<" ";
        preorderRec(ptr->lchild);
        preorderRec(ptr->rchild);
    }
}

void Tree :: inorderRec(NodeT* ptr){
    if(ptr!=NULL){
        inorderRec(ptr->lchild);
        cout<<ptr->data<<" ";
        inorderRec(ptr->rchild);
    }
}

void Tree :: postorderRec(NodeT* ptr){
    if(ptr!=NULL){
        postorderRec(ptr->lchild);
        postorderRec(ptr->rchild);
        cout<<ptr->data<<" ";
    }
}

void Tree :: PreOrderItr(){
    Stack temp;
    NodeT* ptr = root;
    while(ptr != NULL || !temp.isempty()){
        if(ptr != NULL){
            cout<<ptr->data<<" ";
            temp.push(ptr);
            ptr = ptr->lchild;
        }
        else{
            ptr = temp.pop();
            ptr = ptr->rchild;
        }
    }
}

void Tree :: InOrderItr(){
    Stack temp;
    NodeT* ptr = root;
    while(ptr != NULL || !temp.isempty()){
        if(ptr != NULL){
            temp.push(ptr);
            ptr = ptr->lchild;
        }
        else{
            ptr = temp.pop();
            cout<<ptr->data<<" ";
            ptr = ptr->rchild;
        }
    }
}

void Tree :: PostOrderItr(){
    Stack temp;
    NodeT* ptr = root;
    
    while(ptr != NULL || !temp.isempty()){
        if(ptr != NULL){
            if(ptr->rchild != NULL){
                temp.push(ptr->rchild);
            } 
            temp.push(ptr);
            ptr = ptr->lchild;     
        }
        else{
            ptr = temp.pop();
            if(temp.TOS() != ptr->rchild){
                cout<<ptr->data<<" ";
                ptr = NULL;
            }
            else{
                NodeT* tempPtr = temp.pop();
                temp.push(ptr);
                ptr = tempPtr;
            }
        }
    }
}

int Tree :: count_internalNode(NodeT* ptr){
    if (ptr == NULL)
    return 0;
    else{
        if(ptr->lchild || ptr->rchild){
            return count_internalNode(ptr->lchild) + count_internalNode(ptr->rchild) + 1;
        }
        else{
            return count_internalNode(ptr->lchild) + count_internalNode(ptr->rchild);
        }
    }
}

int Tree :: count_leafNode(NodeT* ptr){
    if (ptr == NULL)
    return 0;
    else{
        if(ptr->lchild == NULL && ptr->rchild == NULL){
            return count_leafNode(ptr->lchild) + count_leafNode(ptr->rchild) + 1;
        }
        else{
            return count_leafNode(ptr->lchild) + count_leafNode(ptr->rchild);
        }
    }
}


int Tree :: height(NodeT* ptr){
    if(ptr == NULL)
    return -1;
    else{
        int hleft = height(ptr->lchild);
        int hright = height(ptr->rchild);
        if(hleft > hright){
            return hleft + 1;
        }
        else{
            return hright + 1;
        }
    }
}

void Tree :: mirrorTree(NodeT* ptr){
    if(ptr != NULL){
        if(ptr->lchild || ptr->rchild){
            NodeT* temp = ptr->rchild;
            ptr->rchild = ptr->lchild;
            ptr->lchild = temp;
        }
        mirrorTree(ptr->lchild);
        mirrorTree(ptr->rchild);
    }
}

void Tree :: operator = (Tree o){
    this->root = this->copy(o.getRoot());
}

void Tree :: Delete(NodeT* ptr){
    if(ptr){
        Delete(ptr->lchild);
        Delete(ptr->rchild);
        delete ptr;
    }
}

Tree :: ~Tree(){
    Delete(this->getRoot());
}


//Driver code
int main(){
    Tree t1;
    t1.create();
    cout<<endl;
    cout<<"PreOrder traversal- "<<endl;
    t1.preorderRec(t1.getRoot());
    cout<<endl;
    cout<<"Number of internal nodes: "<<t1.count_internalNode(t1.getRoot())<<endl;
    cout<<"Number of leaf nodes: "<<t1.count_leafNode(t1.getRoot())<<endl;
    cout<<"Height of tree: "<<t1.height(t1.getRoot())<<endl;
    cout<<endl;
    cout<<"After mirroring the tree-"<<endl;
    t1.mirrorTree(t1.getRoot());
    cout<<"PreOrder traversal- "<<endl;
    t1.preorderRec(t1.getRoot());
    cout<<endl;
    Tree t2;
    t2 = t1;
    cout<<endl;
    cout<<"Copied tree is-"<<endl;
    t2.PreOrderItr();
    
    return 0;
}

/*
Output:
Enter data of root node: 1

Enter lchild data of '1' : 2

Enter rchild data of '1' : 3

Enter lchild data of '2' : 4

Enter rchild data of '2' : 5

Enter lchild data of '3' : 6

Enter rchild data of '3' : 7

Enter lchild data of '4' : -1

Enter rchild data of '4' : -1

Enter lchild data of '5' : -1

Enter rchild data of '5' : -1

Enter lchild data of '6' : -1

Enter rchild data of '6' : -1

Enter lchild data of '7' : -1

Enter rchild data of '7' : -1

PreOrder traversal-
1 2 4 5 3 6 7
Number of internal nodes: 3
Number of leaf nodes: 4
Height of tree: 2

After mirroring the tree-
PreOrder traversal-
1 3 7 6 2 5 4 

Copied tree is-
1 3 7 6 2 5 4
*/
