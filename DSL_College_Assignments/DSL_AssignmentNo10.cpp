#include<iostream>
#include<string>
using namespace std;

template<class T>
struct Node{
	T data;
	Node<T>* next;	
};

template<class T>
class Stack{
	Node<T>* top;
	public:
		Stack(){
		top = NULL;
		}
		
		~Stack(){
		Node<T>* ptr = new Node<T>;
		Node<T>* temp = new Node<T>;
		ptr = top;
		while(ptr != NULL){
			temp = ptr;
			ptr = ptr->next;
			temp->next = NULL;
			delete temp;
			}
		}

		
		bool isempty(){
			if(top == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(T item){
			if(top == NULL){
			top = new Node<T>;
			top->data = item;
			top->next = NULL;
			}
	
			else{
				Node<T>* newNode = new Node<T>;
				newNode->data = item;
				newNode->next = top;
				top = newNode;
			}
		}
		
		void pop(){
			if(top == NULL){
				return;
			}
			else{
				Node<T>* temp = new Node<T>;
				temp = top;
				top = top->next;
				temp->next = NULL;
				delete temp;
			}
		}
		
		void  display(){
			cout<<endl;
			cout<<"Below is the stored Stack in the heap memory-"<<endl;
			Node<T>* ptr = new Node<T>;
			ptr = top;
			cout<<"Address of 'TOP of STACK' is: "<<ptr<<endl;
			while(ptr != NULL){
				cout<<"Address: "<<ptr<<" -> Data: "<<ptr->data<<endl;
				ptr = ptr->next;
			}
		}
		
		T getTop(){
			return top->data;
		}
};

class expression{
	string exp;
	public:
		expression(){
			exp = "\0";
		}
		
		expression(string in_exp){
			exp = in_exp;
		}
		
		bool isPostfix(){
			int len = exp.length();
			char item = exp[len-1];
			if(item == '+' || item == '-' || item == '*' || item == '/'){
				return true;
			}
			else{
				return false;
			}
		}
		
		int precedence(char opr){
					if(opr == '*' || opr =='/'){
					return 2;
				}
				else if(opr == '+' || opr == '-'){
					return 1;
				}
				else{
					return -1;
				}
			}
			
		string infixTopostfix(){
			int len = exp.length(), i = 0;
			string convExp;
			Stack<char> Operator;
			while(i < len){
				char ch = exp[i];
				
				if(ch >= '0' && ch <= '9'){
					convExp += ch;
				}
				
				else if(ch == '('){
					Operator.push(ch);
				}
				
				else if(ch == ')'){
					while(Operator.getTop() != '('){
						convExp += Operator.getTop();
						Operator.pop();
					}
					Operator.pop();
				}
				
				else{
					while(!Operator.isempty() && precedence(ch) <= precedence(Operator.getTop())){
						if(Operator.getTop() == '('){
							break;
						}
						convExp += Operator.getTop();
						Operator.pop();
					}
					Operator.push(ch);
				}
				i++;
			}
			
			while(!Operator.isempty()){
				convExp += Operator.getTop();
				Operator.pop();
			}
			
			exp = convExp;
			return convExp;
		}
		
		float evalExp(){
		Stack<float> operands;
		int len = exp.length();
		int i = 0;
		float result;
		while(i < len){
			char item = exp[i];
				
			//If item is operator
			if(item == '+' || item == '-' || item == '*' || item == '/'){
				switch (item){
					case '+':{
						int op2 = operands.getTop();
						operands.pop();
						int op1 = operands.getTop();
						operands.pop();
						result = op1 + op2;
						operands.push(result);	
					}
						break;
						
					case '-':{
						int op2 = operands.getTop();
						operands.pop();
						int op1 = operands.getTop();
						operands.pop();
						result = op1 - op2;
						operands.push(result);
		 		    }
						break;
						
					case '*':{
						int op2 = operands.getTop();
						operands.pop();
						int op1 = operands.getTop();
						operands.pop();
						result = op1 * op2;
						operands.push(result);
					}
						break;
							
					case '/':{
						int op2 = operands.getTop();
						operands.pop();
						int op1 = operands.getTop();
						operands.pop();
						result = (float)op1 / op2;
						operands.push(result);
					}
						break;
					}
				}
				
				//Else item is operand
				else{
					int op = item - '0';
					operands.push(op);
				}
				i++;
			}
		result = operands.getTop();
		return result;
	}
		
};

int main(){
	
	string exp;
	cout<<"Enter expression: ";
	cin>>exp;
	
	expression exp1(exp);
	
	cout<<"Input expression is: "<<exp<<endl;
	if(exp1.isPostfix()){
		cout<<"Its a Postfix expression"<<endl;
	}
	else{
		cout<<"Its not a Postfix expression"<<endl;
		exp = exp1.infixTopostfix();
		cout<<"Converted postfix expression is: "<<exp<<endl;	
	}
	
	
	float result = exp1.evalExp();
	cout<<"Evaluation of postfix expression is: "<<result<<endl;;
	return 0;
}

/*
OUTPUT:
Enter expression: 1*(2*3+4*5)+6
Input expression is: 1*(2*3+4*5)+6
Its not a Postfix expression
Converted postfix expression is: 123*45*+*6+
Evaluation of postfix expression is: 32

--------------------------------
Process exited after 31.72 seconds with return value 0
Press any key to continue . . .

Enter expression: 23+3*2/
Input expression is: 23+3*2/
Its a Postfix expression
Evaluation of postfix expression is: 7.5

--------------------------------
Process exited after 133 seconds with return value 0
Press any key to continue . . .
.

*/

