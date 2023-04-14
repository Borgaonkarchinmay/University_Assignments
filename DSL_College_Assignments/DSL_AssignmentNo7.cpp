#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

class DLL{
	struct Node* head;
	public:
		DLL();
		~DLL();
		void addToDLL(int);
		void convTobin(int);
		int length();
		void dispDLL();
		void oneScomp();
		void twoScomp();
		DLL binAdd(DLL);
};
		

DLL :: DLL(){
	head = NULL;
} 


void DLL :: addToDLL(int item){
	//If DLL is empty, allocate memory to head node
	if(head == NULL){
		head = new Node;
		head->data = item;
		head->next = NULL;
		head->prev = NULL;
	} 
	
	//If DLL is not empty, then create a new node and insert before head
	else{
		//Create a new Node
		Node* newNode = new Node;
		newNode->data = item;
		newNode->prev = NULL;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void DLL :: dispDLL(){
	Node* ptr = head;
	cout<<"\nBinary representation: ";
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;	
	}
	cout<<endl;
}

void DLL ::convTobin(int no){
	// If number is 0 directly insert it in DLL
	if(no == 0){
		addToDLL(no);
	}
	
	//If number is 1 directly insert it in DLL
	else if(no == 1){
		addToDLL(no);
	}
	
	//If number is other than 0 and 1 then convert and insert it in DLL
	else{
		while(true){
			int bit;
			bit = no%2;
			addToDLL(bit);
			no = no/2;
			if(no == 1){
				addToDLL(1);
				break;
			}
		}
	}
}

void DLL :: oneScomp(){
	Node* ptr = head;
	
	//If DLL is empty
	if(head == NULL){
		return;
	}
	
	else{
		
		//Toggle every bit
		while(ptr != NULL){
			if(ptr->data == 0){
				ptr->data = 1;
			}
			
			else if(ptr->data == 1){
				ptr->data = 0;
			}
			
			else{
				return;
			}
			
			ptr = ptr->next;
		}
	}
}

void DLL :: twoScomp(){
	// Perform 1's complement
	oneScomp();
	Node* ptr = head;
	
	//Take pointer to last node
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	
	int carry = 0;
	
	if(ptr->data == 0){
		ptr->data =1;
	}
	
	else{
		ptr->data = 0;
		carry = 1;
		while(ptr->prev != NULL && carry == 1){
			ptr = ptr->prev;
			if(ptr->data == 1){
				ptr->data = 0;
				carry = 1;
			}
			
			else{
				ptr->data = 1;
				carry = 0;
			}
		}
		
		if(carry == 1){
			addToDLL(1);
		}
	}
}

DLL DLL :: binAdd(DLL obj){
	DLL result;
	Node* ptr1 = new Node;
	Node* ptr2 = new Node;
	
	if(length() <= obj.length()){
		ptr2 = head;
		ptr1 = obj.head;
	}
	
	else{
		ptr2 = obj.head;
		ptr1 = head; 
	}
	
	int carry = 0;
	//Take pointers to last node
	while(ptr1->next != NULL){
		ptr1 = ptr1->next;
	}
	while(ptr2->next != NULL){
		ptr2 = ptr2->next;
	}
	
	//First complete addition of smaller DLL with bigger DLL
	while(ptr2 != NULL){
		if(ptr1->data == 0 && ptr2->data == 0 && carry == 0){
			result.addToDLL(0);
			carry = 0;
		}
		
		else if(ptr1->data == 0 && ptr2->data == 0 && carry == 1){
			result.addToDLL(1);
			carry = 0;
		}
		
		else if(ptr1->data == 0 && ptr2->data == 1 && carry == 0){
			result.addToDLL(1);
			carry = 0;
		}
		
		else if(ptr1->data == 0 && ptr2->data == 1 && carry == 1){
			result.addToDLL(0);
			carry = 1;
		}
		
		else if(ptr1->data == 1 && ptr2->data == 0 && carry == 0){
			result.addToDLL(1);
			carry = 0;
		}
		
		else if(ptr1->data == 1 && ptr2->data == 0 && carry == 1){
			result.addToDLL(0);
			carry = 1;
		}
		
		else if(ptr1->data == 1 && ptr2->data == 1 && carry == 0){
			result.addToDLL(0);
			carry = 1;
		}
		
		else if(ptr1->data == 1 && ptr2->data == 1 && carry == 1){
			result.addToDLL(1);
			carry = 1;
		}
		
		//Shift towards MSB
		ptr1 = ptr1->prev;
		ptr2 = ptr2->prev;
	}
	
	//If carry is not generated at MSB of smaller DLL
	if(carry == 0){
		while(ptr1 != NULL){
			result.addToDLL(ptr1->data);
			ptr1 = ptr1->prev;
		}
		return result;
	}
	
	else{
		while(ptr1 != NULL && carry == 1){
			if(ptr1->data == 1){
				result.addToDLL(0);
				carry = 1;
			}
			
			else{
				result.addToDLL(1);
				carry = 0;
			}
			
			//Shift towards MSB of bigger DLL
			ptr1 = ptr1->prev;
		}
		
		//If carry is 1
		if(carry == 1){
			result.addToDLL(1);
			return result;
		}
		
		else{
			while(ptr1 != NULL){
				result.addToDLL(ptr1->data);
				ptr1 = ptr1->prev;
			}
			return result;
		}
	}
}

int DLL :: length(){
	Node* ptr = head;
	int len = 1;
	
	if(head == NULL){
		return 0;
	}
	
	else{
		while(ptr->next != NULL){
			ptr = ptr->next;
			len++;
		}
	}
	
	return len;
}


DLL :: ~DLL(){
	Node* temp = new Node;
	Node* ptr = head;
	while(ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}

int main(){
	DLL num1, num2, add;
	int no1, no2, menu;
	char choice = 'y';
	
	//Input numbers
	cout<<"Enter 1st number: ";
	cin>>no1;
	cout<<"Enter 2nd number: ";
	cin>>no2;
				
	//Convert integer to binary and store in DLL
	num1.convTobin(no1);
	num2.convTobin(no2);
				
	//Display the two numbers and their length
	cout<<"\nNumber 1 is: "<<no1;
	num1.dispDLL();
	cout<<"\nNumber 2 is: "<<no2;
	num2.dispDLL();
				
	//Display length of DLL		
	cout<<endl;
	cout<<"Length of num1 is: "<<num1.length()<<endl;
	cout<<"Length of num2 is: "<<num2.length()<<endl;
	
	

		
		//Display menu to user
		cout<<"\n***MENU***"<<endl;
		cout<<"1-> 1's complement of two numbers\n2-> 2's complement of two numbers\n3-> Binary addition of two numbers"<<endl;
		cout<<"Enter Menu: ";
		cin>>menu;
		
		//Execute mentioned operation
		switch(menu){
			case 1:
				cout<<endl;
				cout<<"1's complement of 1st num is- ";
				num1.oneScomp();
				num1.dispDLL();
				cout<<endl;
				cout<<"1's complement of 2nd num is- ";
				num2.oneScomp();
				num2.dispDLL();
				break;
			
			case 2:
				cout<<endl;
				cout<<"2's complement if 1st num- ";
				num1.twoScomp();
				num1.dispDLL();
				cout<<endl;
				cout<<"2's complement if 2nd num is- ";
				num2.twoScomp();
				num2.dispDLL();
				break;
			
			case 3:
				//DLL addition;
				//addition = num1.binAdd(num2);
				cout<<"Binary addition of "<<no1<<" and "<<no2<<":";
				num1.binAdd(num2).dispDLL();
				break;
				
			default:
				cout<<"Invalid input!!"<<endl;
				break;
		}
		
	return 0;
}

/*
output:

Menu: 1

Enter 1st number: 36
Enter 2nd number: 112

Number 1 is: 36
Binary representation: 1 0 0 1 0 0

Number 2 is: 112
Binary representation: 1 1 1 0 0 0 0

Length of num1 is: 6
Length of num2 is: 7

***MENU***
1-> 1's complement of two numbers
2-> 2's complement of two numbers
3-> Binary addition of two numbers
Enter Menu: 1

1's complement of 1st num is-
Binary representation: 0 1 1 0 1 1

1's complement of 2nd num is-
Binary representation: 0 0 0 1 1 1 1

--------------------------------
Process exited after 52.92 seconds with return value 0
Press any key to continue . . .

Menu: 2

Enter 1st number: 26
Enter 2nd number: 87

Number 1 is: 26
Binary representation: 1 1 0 1 0

Number 2 is: 87
Binary representation: 1 0 1 0 1 1 1

Length of num1 is: 5
Length of num2 is: 7

***MENU***
1-> 1's complement of two numbers
2-> 2's complement of two numbers
3-> Binary addition of two numbers
Enter Menu: 2

2's complement if 1st num-
Binary representation: 0 0 1 1 0

2's complement if 2nd num is-
Binary representation: 0 1 0 1 0 0 1

--------------------------------
Process exited after 8.523 seconds with return value 0
Press any key to continue . . .

Menu: 3

Enter 1st number: 39
Enter 2nd number: 127

Number 1 is: 39
Binary representation: 1 0 0 1 1 1

Number 2 is: 127
Binary representation: 1 1 1 1 1 1 1

Length of num1 is: 6
Length of num2 is: 7

***MENU***
1-> 1's complement of two numbers
2-> 2's complement of two numbers
3-> Binary addition of two numbers
Enter Menu: 3
Binary addition of 39 and 127:
Binary representation: 1 0 1 0 0 1 1 0

--------------------------------
Process exited after 11.11 seconds with return value 3221226356
Press any key to continue . . .

*/
