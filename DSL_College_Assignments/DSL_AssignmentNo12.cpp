#include<iostream>
using namespace std;

//Class Job
class Job{
	int ID, priority;
	float duration;
	public:
		Job();
		Job(int, float, int);
		void getJobDetails(int, float, int);
		void dispJob();
		bool operator <=(Job&); //Comparison based on priority of job
};

Job :: Job(){
	ID = 0;
	priority = 0;
	duration = 0.0;
}

Job :: Job(int id, float dur, int prio){
	ID = id;
	duration = dur;
	priority = prio;
}

void Job :: getJobDetails(int id, float dur, int prio){
	ID = id;
	priority = prio;
	duration = dur;
}

void Job :: dispJob(){
	cout<<"(Job-> Priority: "<<priority<<", ID: "<<ID<<", Duration: "<<duration<<")";
}

bool Job :: operator <=(Job& obj){
	if(priority <= obj.priority){
		return true;
	}
	else{
		return false;
	}
}

//Queue
struct Node{
	Job data;
	Node* next;
};

class Queue{
	Node* front;
	Node* rear;
	public:
		Queue();
		~Queue();
		void display();
		void insertion(Job&);
		void deletion();
};

Queue :: Queue(){
	front = NULL;
	rear = NULL;
}

void Queue :: insertion(Job& job){
	//Check if Queue is empty
	//Queue is empty only if rear pointer is NULL
	if(rear == NULL){
		rear = new Node;
		rear->data = job; //Store object of Job in queue
		rear->next = NULL;
		front = rear;
	}
	
	//If Queue is Non-Empty
	else{
		//Create a newNode to store the job
		Node* newNode = new Node;
		newNode->data = job;
		
		//Check the priority and then insert accordingly
		//If job priority is less than job at rear
		if(newNode->data <= rear->data){
			newNode->next = rear;
			rear = newNode;
		}
		
		else{
			Node* curr = new Node;
			Node* prev = new Node;
			curr = rear->next;
			prev = rear;
			
			while(curr != NULL && !(newNode->data <= curr->data)){
				curr = curr->next;
				prev = prev->next;
			}
			
			if(curr != NULL){
				newNode->next = curr;
				prev->next = newNode;
			}
			
			else{
				newNode->next = NULL;
				prev->next = newNode;
				front = newNode;
			}
		}
	}
}

void Queue :: deletion(){
	//Check if Queue is Empty
	if(rear == NULL){
		cout<<"Queue is Empty!!\nFurther deletion not possible."<<endl;
		return;
	}
	//If Queue is Non-Empty
	else{
		//If there are more than one elements in Queue
		if(front != rear){
			Node* curr = new Node;
			Node* prev = new Node;
			curr = rear->next;
			prev = rear;
			while(curr->next != NULL){
				curr = curr->next;
				prev = prev->next;
			}
			prev->next = NULL;
			front = prev;
			delete curr;
		}
		
		//If only one element is there is Queue
		else{
			delete rear;
			front = NULL;
		}
	}
}

void Queue :: display(){
	
	cout<<endl;
	cout<<"Stored Queue is: "<<endl;
	Node* ptr = new Node;
	ptr = rear;
	cout<<"Rear: ";
	ptr->data.dispJob();
	while(ptr->next != NULL){
		ptr = ptr->next;
		cout<<" -> ";
		ptr->data.dispJob();
	}
	cout<<" :Front"<<endl;
}

Queue :: ~Queue(){
	Node* ptr = new Node;
	Node* temp = new Node;
	ptr = rear;
	while(ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		temp->next = NULL;
		delete temp;
	}
}


int main(){
	//Create a Queue to store Jobs
	Queue job_queue;
	
	cout<<"Implementing  Priority Queue:"<<endl;
	while(true){
		int menu;
		cout<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"MENU\n1-> Insert new Job\n2-> Display Jobs in Queue\n3-> Delete Job\n4-> Exit"<<endl;
		cout<<"Enter menu:";
		cin>>menu;
		switch(menu){
			case 1:{
				//Insert new Job
				int job_id, job_prio;
				float job_dur;
				cout<<endl;
				cout<<"Enter new Job details-"<<endl;
				cout<<"Enter Job ID: ";
				cin>>job_id;
				cout<<"Enter Job duration: ";
				cin>>job_dur;
				cout<<"Enter Job Priority: ";
				cin>>job_prio;
				//Create a new pointer to Job object and store it in queue
				Job *ptr = new Job;
				ptr->getJobDetails(job_id, job_dur, job_prio);
				job_queue.insertion(*ptr);
			}
				break;
			
			case 2:{
				//Display Jobs in Queue
				cout<<endl;
				cout<<"Jobs in queue are-"<<endl;
				job_queue.display();
			}
				break;
			
			case 3:{
				//Remove Job from Queue
				cout<<endl;
				cout<<"Deleting the job from queue"<<endl;
				job_queue.deletion();
				cout<<"Job deleted successfully"<<endl;
			}
				break;
			
			case 4:{
				exit(0);
			}
				break;
		}
	}
	
	return 0;
}

/*
--------------------
OUTPUT:
Implementing  Priority Queue:

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 1
Enter Job duration: 5.6
Enter Job Priority: 4

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 4, ID: 1, Duration: 5.6) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 2
Enter Job duration: 0.96
Enter Job Priority: 1

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 4, ID: 1, Duration: 5.6) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 3
Enter Job duration: 1.23
Enter Job Priority: 1

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 4, ID: 1, Duration: 5.6) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 4
Enter Job duration: 1.54
Enter Job Priority: 2

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 2, ID: 4, Duration: 1.54) -> (Job-> Priority: 4, ID: 1, Duration: 5.6) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 5
Enter Job duration: 10.56
Enter Job Priority: 3

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 2, ID: 4, Duration: 1.54) -> (Job-> Priority: 3, ID: 5, Duration: 10.56) -> (Job-> Priority: 4, ID: 1, Duration: 5.6) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 6
Enter Job duration: 11.26
Enter Job Priority: 1

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 6, Duration: 11.26) -> (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 2, ID: 4, Duration: 1.54) -> (Job-> Priority: 3, ID: 5, Duration: 10.56) -> (Job-> Priority: 4, ID: 1, Duration: 5.6) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 7
Enter Job duration: 2.95
Enter Job Priority: 5

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 6, Duration: 11.26) -> (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 2, ID: 4, Duration: 1.54) -> (Job-> Priority: 3, ID: 5, Duration: 10.56) -> (Job-> Priority: 4, ID: 1, Duration: 5.6) -> (Job-> Priority: 5, ID: 7, Duration: 2.95) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:3

Deleting the job from queue
Job deleted successfully

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 6, Duration: 11.26) -> (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 2, ID: 4, Duration: 1.54) -> (Job-> Priority: 3, ID: 5, Duration: 10.56) -> (Job-> Priority: 4, ID: 1, Duration: 5.6) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:3

Deleting the job from queue
Job deleted successfully

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 6, Duration: 11.26) -> (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 2, ID: 4, Duration: 1.54) -> (Job-> Priority: 3, ID: 5, Duration: 10.56) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:3

Deleting the job from queue
Job deleted successfully

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 6, Duration: 11.26) -> (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) -> (Job-> Priority: 2, ID: 4, Duration: 1.54) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:3

Deleting the job from queue
Job deleted successfully

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Rear: (Job-> Priority: 1, ID: 6, Duration: 11.26) -> (Job-> Priority: 1, ID: 3, Duration: 1.23) -> (Job-> Priority: 1, ID: 2, Duration: 0.96) :Front

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:4

--------------------------------
Process exited after 354.3 seconds with return value 0
Press any key to continue . . .




*/
