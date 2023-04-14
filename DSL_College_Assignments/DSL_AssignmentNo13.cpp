//DE-Queue
//Double ended queue
#include<iostream>
using namespace std;

//Node
struct Node{
    int data;
    Node* next;
    Node* prev;
};

//DE-Queue
class DEQueue{
    Node* front;
    Node* rear;
    public:
    DEQueue();
    ~DEQueue();
    void enqueFront(int);
    void enqueRear(int);
    void dequeFront();
    void dequeRear();
    void display();

};

//Member function definition
DEQueue :: DEQueue(){
    front = NULL;
    rear = NULL;
}

void DEQueue :: enqueFront(int data){
    //If queue is empty
    if(front == NULL){
        front = new Node;
        front->data = data;
        front->next = NULL;
        front->prev = NULL;
        rear = front;
    }
    //Else queue is non-empty
    else{
        Node* newNode= new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = front;
        front->next = newNode;
        front = newNode;
    }
}

void DEQueue :: enqueRear(int data){
    //If queue is empty
    if(front == NULL){
        rear = new Node;
        rear->data = data;
        rear->next = NULL;
        rear->prev = NULL;
        front = rear;
    }
    //Else queue is non-empty
    else{
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = rear;
        rear->prev = newNode;
        rear = newNode;
    }
}

void DEQueue :: dequeFront(){
    //If queue is empty
    if(front == NULL){
        cout<<"Queue is empty!!"<<endl;
        return;
    }
    //else queue is non-empty
    else{
        //If one node is present
        if(front == rear){
            delete front;
            rear = NULL;
            front = NULL;
        }
        //Else more than one node is present
        else{
            Node* temp = new Node;
            temp = front;
            front = front->prev;
            front->next = NULL;
            delete temp;
        }
    }
}

void DEQueue :: dequeRear(){
    //If queue is empty
    if(front == NULL){
        cout<<"Queue is empty!!"<<endl;
        return;
    }
    //Else queue is non-empty
    else{
        //If one node is present
        if(front == rear){
            delete rear;
            front = NULL;
            rear = NULL;
        }
        //Else more than one node is present
        else{
            Node* temp = new Node;
            rear = rear->next;
            rear->prev = NULL;
            delete temp;
        }
    }
}

void DEQueue :: display(){
    if(front == NULL){
        cout<<"Queue is empty!!"<<endl;
        return;
    }
    else{
        Node* ptr = new Node;
        ptr = front;
        cout<<"Front:"<<endl;
        while(ptr != NULL){
            cout<<ptr->data<<endl;
            ptr = ptr->prev;
        }
        cout<<"Rear:"<<endl;
    }
}

DEQueue :: ~DEQueue(){
    Node* temp = new Node;
    Node* ptr = new Node;
    ptr = front;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->prev;
        delete temp;
    }
}

//Driver code
int main(){
    DEQueue SE1;
    SE1.enqueFront(12);
    SE1.enqueFront(1);
    SE1.enqueFront(5);
    cout<<endl;
    SE1.display();
    cout<<endl;

    SE1.enqueRear(18);
    SE1.enqueRear(100);
    SE1.display();
    cout<<endl;

    SE1.dequeFront();
    SE1.dequeFront();
    SE1.display();
    cout<<endl;

    SE1.dequeRear();
    SE1.dequeRear();
    SE1.dequeRear();
    SE1.display();
    cout<<endl;
    
    return 0;
}

/*
OUTPUT:

Front:
5
1
12
Rear:

Front:
5
1
12
18
100
Rear:

Front:
12
18
100
Rear:

Queue is empty!!
*/