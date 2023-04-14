/*
Create an inordered threaded binary tree and perform inorder and preorder traversals.
Analyze time and space complexity of the algorithm.
*/
#include<iostream>
using namespace std;
struct NodeT{
    int data;
    bool lbit, rbit;
    NodeT *lchild, *rchild;
    //False = thread
    //True = child
};

class TBT{
    NodeT* head;
    public:
    TBT();
    void create();
    void insert(NodeT*, int);
    void inOrder();
    void preOrder();
    NodeT* leftMost(NodeT*);
    NodeT* getHead(){return head;}
};

TBT :: TBT(){
	head = new NodeT;
	head->data = 0;
	head->lbit = false;
	head->lchild = head;
	head->rbit = true;
	head->rchild = head;
}

void TBT :: inOrder(){

	NodeT* p = leftMost(this->getHead()->lchild);
    while(p != head){
        cout<<p->data<<" ";
        if(p->rbit){
        	p = leftMost(p->rchild);
        }
        else{
        	p = p->rchild;
        }

    }
}

void TBT :: insert(NodeT* p, int data){
    if(!head->lbit){
    	NodeT* newNode = new NodeT;
    	newNode->data = data;
    	newNode->lbit = newNode->rbit = false;
    	newNode->lchild = head;
        newNode->rchild = head;
        head->lchild = newNode;
        head->lbit = true;
    }
    else{
    	//Move to the root of our tree from dummy node
    	p = p->lchild;
        while(true){
            if(data < p->data && p->lbit)
                p = p->lchild;
            else if(data > p->data && p->rbit)
                p = p->rchild;
            else
                break;
        }

        NodeT* newNode = new NodeT;
        newNode->data = data;
        newNode->lbit = newNode->rbit = false;
        newNode->lchild = newNode->rchild = nullptr;

        if(newNode->data < p->data){
            newNode->lchild = p->lchild;
            newNode->rchild = p;
            p->lchild = newNode;
            p->lbit = true;
        }
        else{
            newNode->lchild = p;
            newNode->rchild = p->rchild;
            p->rchild = newNode;
            p->rbit = true;
        }
    }
}

NodeT* TBT :: leftMost(NodeT* p){
    if(!p)
        return nullptr;
    else{
        while(p->lbit)
            p = p->lchild;
        return p;
    }
}

void TBT :: preOrder(){
	if(head->lbit){
		NodeT* p = head->lchild;
		while(p != head){
			while(p->lbit){
				cout<<p->data<<" ";
				p = p->lchild;
			}
			cout<<p->data<<" ";
			while(!p->rbit){
				p = p->rchild;
			}
			p = p->rchild;
		}
	}
}

void TBT :: create(){
	int data = 0;
	char choice;
	while(choice == 'y' && choice != 'n'){
		cout<<endl;
		cout<<"Enter data: ";
		cin>>data;
		insert(getHead(), data);
		cout<<endl;
		cout<<"Do you want to continue?('y'/'n'): ";
		cin>>choice;
		if(choice == 'y' || choice == 'n'){
			continue;
		}
		else{
			cout<<"Invalid choice"<<endl;
			break;
		}
	}


}

int main(){
    TBT t1;
    t1.insert(t1.getHead(), 12);
    t1.insert(t1.getHead(), 8);
    t1.insert(t1.getHead(), 21);
    t1.insert(t1.getHead(), 4);
    t1.insert(t1.getHead(), 17);
    t1.insert(t1.getHead(), 26);
    t1.insert(t1.getHead(), 2);
    t1.insert(t1.getHead(), 6);

    /*
    t1.insert(t1.getHead(), 12);
    t1.insert(t1.getHead(), 8);
    t1.insert(t1.getHead(), 4);
    t1.insert(t1.getHead(), 2);
    */

    cout<<endl;
    cout<<"Inorder- "<<endl;
    t1.inOrder();
    cout<<endl;
    cout<<endl;
    cout<<"Preorder- "<<endl;
    t1.preOrder();
    cout<<endl;
    return 0;
}

/*
Output:
Inorder- 
2 4 6 8 12 17 21 26 

Preorder- 
12 8 4 2 6 21 17 26 
*/
