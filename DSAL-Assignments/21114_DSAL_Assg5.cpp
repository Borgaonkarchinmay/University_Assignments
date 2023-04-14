#include <iostream>
using namespace std;

//Dictionary Node
struct Node{
	string key, meaning;
	Node* next;
};

//Linked list for separate chaining
class linkedlist{
	Node* head;
public:
	linkedlist(){head = nullptr;}
	void insertion(string, string);
	void deletion(string);
	string search(string);
	void display();
	~linkedlist();
};

void linkedlist :: insertion(string key, string meaning){
	if(!head){
		//Linked list is empty
		head = new Node;
		head->key = key;
		head->meaning = meaning;
		head->next = nullptr;
	}
	else{
		//Non empty linked list
		//tracking pointers
		Node* p = nullptr;
		Node* c = head;

		//Search for correct key position
		while(c != nullptr && key > c->key){
			p = c;
			c = c->next;
		}

		if(c){
			if(p){
				//Key in between the LL
				Node* newNode = new Node;
				newNode->key = key;
				newNode->meaning = meaning;
				newNode->next = c;
				p->next = newNode;
			}
			else{
				//Key is smallest in LL
				Node* newNode = new Node;
				newNode->key = key;
				newNode->meaning = meaning;
				newNode->next = c;
				head = newNode;
			}
		}

		else{
			//Largest key in LL
			Node* newNode = new Node;
			newNode->key = key;
			newNode->meaning = meaning;
			newNode->next = nullptr;
			p->next = newNode;
		}
	}
}

void linkedlist :: display(){
	if(head){
		Node* p = head;
		cout<<"("<<p->key<<" :"<<p->meaning<<")";
		p = p->next;
		while(p){
			cout<<", ("<<p->key<<" :"<<p->meaning<<")";
			p = p->next;
		}
	}
}

void linkedlist :: deletion(string key){
	if(head){
		Node* c = head;
		Node* p = nullptr;
		while(c != nullptr && key != c->key){
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

string linkedlist :: search(string key){
	if(head){
		Node* p = head;
		while(p != nullptr && key != p->key){
			p = p->next;
		}
		if(p){
			return p->meaning;
		}
		else{
			return "-1";
		}
	}
	else{
		return "-1";
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

//Open Hash table
class Hash{
	linkedlist* hashArr[26];
	public:
	Hash();
	int hashVal(string);
	string searchKey(string);
	void insertKey(string, string);
	void display();
	void deleteKey(string);
	~Hash();
};

Hash :: Hash(){
	for(int i = 0; i<26; i++)
		hashArr[i] = nullptr;
}

int Hash :: hashVal(string key){
	char firstChar = key[0];
	int ascii = int(firstChar);
	if(ascii >=97 && ascii <= 122){
		//starting with small letters
		return ascii % 97;
	}
	else if(ascii >=65 && ascii <= 90){
		//starting with capital letters
		return ascii % 65;
	}
	else{
		return -1;
	}
}

string Hash :: searchKey(string key){
	int index = hashVal(key);
	if(index != -1){
		if(hashArr[index])
			return hashArr[index]->search(key);
		else{
			return "-1";
		}
	}
	else{
		//Entered key is invalid
		return "0";
	}
}

void Hash :: insertKey(string key, string meaning){
	int index = hashVal(key);
	if(index != -1){
		if(!hashArr[index]){
			hashArr[index] = new linkedlist;
			hashArr[index]->insertion(key, meaning);
		}
		else{
			hashArr[index]->insertion(key, meaning);
		}
	}
	else{
		cout<<endl;
		cout<<"Invalid key!!"<<endl;
	}
}

void Hash :: display(){
	for(int i = 0; i < 26; i++){
		if(hashArr[i]){
			hashArr[i]->display();
			cout<<endl;
		}
	}
}

void Hash :: deleteKey(string key){
	int index = hashVal(key);
	if(index != -1){
		if(hashArr[index])
			hashArr[index]->deletion(key);
		else{
			cout<<endl;
			cout<<"Key Not Found"<<endl;
		}
	}
	else{
		cout<<endl;
		cout<<"Key Not Found"<<endl;
	}
}

Hash :: ~Hash(){
	for(int i =0; i < 26; i++)
		delete hashArr[i];
}


int main() {
	Hash obj;
    char choice = 'y';
	while(choice != 'n' && choice == 'y'){

        int menu=0;
        cout<<"MENU:\n1. Insert New Key\n2. Display Complete Dictionary\n3. Search Key\n4. Delete Key"<<endl;
        cout<<"Enter menu: ";
        cin>>menu;
        switch(menu){
            case 1:{
                //Insert New Key
				string k, m;
				cout<<endl;
				cout<<"Enter Key: ";
				cin>>k;
				cout<<endl;
				cout<<"Enter meaning: ";
				cin>>m;
				obj.insertKey(k, m);
                break;
            }
            case 2:{
                //Display Complete Dictionary
				cout<<endl;
				cout<<"Complete Dictionary is: "<<endl;
				obj.display();
                break;
            }
            case 3:{
                //Search Key
				string k, m;
				cout<<endl;
				cout<<"Enter Key to be Searched: ";
				cin>>k;
				m = obj.searchKey(k);
				if(m == "-1"){
					cout<<endl;
					cout<<"Key not found"<<endl;
				}
				else if(m == "0"){
					cout<<endl;
					cout<<"Invalid Key"<<endl;
				}
				else{
					cout<<endl;
					cout<<"Meaning of "<<"'"<<k<<"'"<<" is: "<<m;

				}
                break;
            }
            case 4:{
                //Delete Key
				string k;
				cout<<endl;
				cout<<"Enter Key to be Deleted: ";
				cin>>k;
				obj.deleteKey(k);
                break;
            }
        }

        cout<<endl;
        cout<<"Do want to continue:?('y'/'n')-> ";
		cin>>choice;
        if(!(choice == 'n' || choice == 'y')){
            cout<<endl;
            cout<<"Invalid menu"<<endl;
            break;
        }
        cout<<endl;
        cout<<"------------------------------------------------"<<endl;
    }

	return 0;
}


/*
OUTPUT:
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: apple
Enter meaning: fruit
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: aurangabad
Enter meaning: city
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: best
Enter meaning: adjective
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: cat
Enter meaning: animal
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: digvijay
Enter meaning: human
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: eagle
Enter meaning: bird
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: fish
Enter meaning: seafood
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 1
Enter Key: goat
Enter meaning: animal
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 2
Complete Dictionary is:
(apple :fruit), (aurangabad :city)
(best :adjective)
(cat :animal)
(digvijay :human)
(eagle :bird)
(fish :seafood)
(goat :animal)
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 3
Enter Key to be Searched: eagle
Meaning of 'eagle' is: bird
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 3
Enter Key to be Searched: mom
Key not found
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 4
Enter Key to be Deleted: apple
Do want to continue:?('y'/'n')-> y
------------------------------------------------
MENU:
1. Insert New Key
2. Display Complete Dictionary
3. Search Key
4. Delete Key
Enter menu: 2
Complete Dictionary is:
(aurangabad :city)
(best :adjective)
(cat :animal)
(digvijay :human)
(eagle :bird)
(fish :seafood)
(goat :animal)
Do want to continue:?('y'/'n')-> n
------------------------------------------------
*/
