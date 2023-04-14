#include<iostream>
#include<string.h>
using namespace std;
struct Node{
	char data;
	Node* next;
};

class Stack{
	Node* top;
	public:
		Stack();
		~Stack();
		void push(char);
		void pop();
		bool isEmpty();
		void display();
		bool parenthesisCheck(string);
		
};

Stack :: Stack(){
	top = NULL;	
}

void Stack :: push(char item){
	//If Stack is empty
	if(top == NULL){
		top = new Node;
		top->data = item;
		top->next = NULL;
	}
	
	//If Stack is not empty
	else{
		Node* newNode = new Node;
		newNode->data = item;
		newNode->next = top;
		top = newNode;
	}
}

void Stack :: pop(){
	//Pop means to delete the top of stack.
	//And update the top of stack to next consecutive Node
	if(top == NULL){
		return;
	}
	
	else{
		Node* temp = new Node;
		temp = top;
		top = top->next;
		temp->next = NULL;
		delete temp;
	}
}

bool Stack :: isEmpty(){
	if(top == NULL){
		return true;
	}
	else{
		return false;
	}
}

void Stack :: display(){
	Node* ptr = new Node;
	ptr = top;
	cout<<"Below is the stored Stack in heap memory"<<endl;
	cout<<"Top of stack is: "<<top<<endl;
	while(ptr != NULL){
		cout<<"Address: "<<ptr<<" -> Data: "<<ptr->data<<endl;
		ptr = ptr->next;
	}
}

bool Stack :: parenthesisCheck(string exp){
	int i = 0;
	int len = exp.length();
	bool flag = true; //To track invalid pop() operation

	while(i < len){
		char brack = exp[i];
		
		
		//If opening brackets encountered, push in Stack
		if(brack == '{' || brack == '[' || brack == '('){
			push(brack);
		}
		
		//If closing brackets encountered, pop the top of stack
		else if(brack == '}' || brack == ']' || brack == ')'){
			
			//Pop only if Stack is Non-empty
			if(top != NULL){
				char TOS = top->data;
				
				//Check the Top of Stack
				if( TOS == '{'){
					if(brack == '}'){
						pop();
					}
					else{
						flag = false;
						break;
					}
				}
				
				else if( TOS == '['){
					if(brack == ']'){
						pop();
					}
					else{
						flag = false;
						break;
					}
				}
				
				else if( TOS == '('){
					if(brack == ')'){
						pop();
					}
					else{
						flag = false;
						break;
					}
				}
			}
				
			
			//If stack is Empty
			else{
				flag = false;
				break;
			}
			
		}
		
		//Increment index counter
		i++;
	}
	
	//Check for the Stack conditions for balanced parenthesis
	if(flag == false){
		return false;
	}
	
	else{
		//If stack is empty then expression is balanced return 'True'
		if(isEmpty()){
			return true;
		}
		else{
			return false;
		}
	}
}
	

Stack :: ~Stack(){
	Node* temp = new Node;
	Node* ptr = new Node;
	while(ptr != NULL){
		temp = ptr;
		ptr = ptr->next;
		temp->next = NULL;
		delete temp;
	}
}

int main(){
	
	//Declare necessary variables
	Stack brackets;
	string input;
		
	//Accept string for parenthesis check
	cout<<"Enter string to perform parenthesis check: ";
	cin>>input;
	cout<<"Input String is: "<<input<<endl;
	
	//Check validity of input expression
	if(brackets.parenthesisCheck(input)){
		cout<<endl;
		cout<<"Input expression is: BALANCED expression"<<endl;
	}
	
	else{
		cout<<endl;
		cout<<"Input expression is: UNBALANCED expression"<<endl;
	}
	
	
	return 0;
}

/*
OUTPUT:
A)
Enter string to perform parenthesis check: {[()()]}
Input String is: {[()()]}

Input expression is: BALANCED expression

--------------------------------
Process exited after 22.66 seconds with return value 3221226356
Press any key to continue . . .

B)
Enter string to perform parenthesis check: [(})]
Input String is: [(})]

Input expression is: UNBALANCED expression

--------------------------------
Process exited after 13.75 seconds with return value 3221226356
Press any key to continue . . .

C)
Enter string to perform parenthesis check: )}{[](
Input String is: )}{[](

Input expression is: UNBALANCED expression

--------------------------------
Process exited after 10.71 seconds with return value 3221226356
Press any key to continue . . .

*/
