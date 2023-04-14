#include<iostream>
using namespace std;

//Class Job
class Job{
	int ID;
	float duration;
	public:
		Job();
		Job(int, float);
		void getJobDetails(int, float);
		void dispJob();
};

Job :: Job(){
	ID = 0;
	duration = 0.0;
}

Job :: Job(int id, float dur){
	ID = id;
	duration = dur;
}

void Job :: getJobDetails(int id, float dur){
	ID = id;
	duration = dur;
}

void Job :: dispJob(){
	cout<<"(Job-> ID: "<<ID<<", Duration: "<<duration<<")";
}

//Queue
struct Node{
	Job data;
	Node* next;
};

class Queue{
	Node* head;
	Node* tail;
	public:
		Queue();
		~Queue();
		void display();
		void insertion(Job&);
		void deletion();
};

Queue :: Queue(){
	head = NULL;
	tail = NULL;
}

void Queue :: insertion(Job& job){
	//Check if Queue is empty
	//Queue is empty only if head pointer is NULL
	if(head == NULL){
		head = new Node;
		head->data = job; //Store object of Job in queue
		head->next = NULL;
		tail = head;
	}
	
	//If Queue is Non-Empty
	else{
		Node* newNode = new Node;
		newNode->data = job; //Store object of Job in queue
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

void Queue :: deletion(){
	//Check if Queue is Empty
	if(head == NULL){
		return;
	}
	//If Queue is Non-Empty
	else{
		//If there are more than one elements in Queue
		if(head != tail){
			Node* temp = new Node;
			temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
		}
		
		//If only one element is there is Queue
		else{
			delete head;
			tail = NULL;
		}
	}
}

void Queue :: display(){
	
	cout<<endl;
	cout<<"Stored Queue is: "<<endl;
	Node* ptr = new Node;
	ptr = head;
	cout<<"Head: ";
	ptr->data.dispJob();
	while(ptr->next != NULL){
		ptr = ptr->next;
		cout<<" <- ";
		ptr->data.dispJob();
	}
	cout<<":Tail"<<endl;
}

Queue :: ~Queue(){
	Node* ptr = new Node;
	Node* temp = new Node;
	ptr = head;
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
	
	cout<<"Implementing Job Queue:"<<endl;
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
				int job_id;
				float job_dur;
				cout<<endl;
				cout<<"Enter new Job details-"<<endl;
				cout<<"Enter Job ID: ";
				cin>>job_id;
				cout<<"Enter Job duration: ";
				cin>>job_dur;
				//Create a new pointer to Job object and store it in queue
				Job *ptr = new Job;
				ptr->getJobDetails(job_id, job_dur);
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
OUTPUT:
Implementing Job Queue:

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 1
Enter Job duration: 0.23

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 2
Enter Job duration: 1.85

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 3
Enter Job duration: 8.95

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 4
Enter Job duration: 7.32

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:1

Enter new Job details-
Enter Job ID: 5
Enter Job duration: 4.2

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:2

Jobs in queue are-

Stored Queue is:
Head: (Job-> ID: 1, Duration: 0.23) <- (Job-> ID: 2, Duration: 1.85) <- (Job-> ID: 3, Duration: 8.95) <- (Job-> ID: 4, Duration: 7.32) <- (Job-> ID: 5, Duration: 4.2):Tail

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
Head: (Job-> ID: 2, Duration: 1.85) <- (Job-> ID: 3, Duration: 8.95) <- (Job-> ID: 4, Duration: 7.32) <- (Job-> ID: 5, Duration: 4.2):Tail

---------------------------------
MENU
1-> Insert new Job
2-> Display Jobs in Queue
3-> Delete Job
4-> Exit
Enter menu:4

--------------------------------
Process exited after 79.65 seconds with return value 0
Press any key to continue . . .


*/
