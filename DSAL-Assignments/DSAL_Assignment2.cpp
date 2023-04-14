//DSAL assignment- 2
//Aim: Create a dictionary
/* Objectives
 1. adding new keyword
 2. deleting keywords
 3. updating keywords
 4. display data in asceding/descending order
 5. how many max comparisons required to search the keyword
 */

#include<iostream>
using namespace std;

//Node structure for BS Tree
struct NodeT{
    string key, meaning;
    NodeT* lchild;
    NodeT* rchild;
};

class BST{
    NodeT* root;
    public:
    BST();
    void ascOrder(NodeT*);
    void desOrder(NodeT*);
    void create();
    void updateKey(NodeT*, string);
    int height(NodeT*);
    int compCount(NodeT*, string);
    NodeT* getRoot();
    NodeT* insert(NodeT*, string, string);
    NodeT* deletion(NodeT*, string);
    NodeT* InPre(NodeT*);
    NodeT* InSucc(NodeT*);
    string searchRec(NodeT*, string);
};

BST :: BST(){
    root = NULL;
}

void BST :: ascOrder(NodeT* ptr){
    if(ptr != NULL){
        ascOrder(ptr->lchild);
        cout<<"(Key: "<<ptr->key<<" ->meaning: "<<ptr->meaning<<")"<<endl;
        ascOrder(ptr->rchild);
    }
}

void BST :: desOrder(NodeT* ptr){
	if(ptr != NULL){
	        desOrder(ptr->rchild);
	        cout<<"(Key: "<<ptr->key<<" ->meaning: "<<ptr->meaning<<")"<<endl;
	        desOrder(ptr->lchild);
	    }
}

void BST :: create(){
	string key, meaning;
	char choice = 'y';
	while(choice != 'n' && choice == 'y'){
		cout<<"Enter key: ";
		cin>>key;
		cout<<endl;
		cout<<"Enter meaning: ";
        cin.ignore();
		getline(cin, meaning);
		this->insert(root, key, meaning);
		cout<<endl;
		cout<<"Do want to continue:?('y'/'n')-> ";
		cin>>choice;
	}
}

void BST :: updateKey(NodeT* ptr, string key){
    if(!ptr)
    	return;
    else{
        if(key == ptr->key){
            string meaning;
            cout<<"Re-Enter key: ";
            cin>>key;
            cout<<endl;
            cout<<"Re-enter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            ptr->key = key;
            ptr->meaning = meaning;
            return;
        }
        else if(key < ptr->key)
        return updateKey(ptr->lchild, key);
        else
        return updateKey(ptr->rchild, key);
    }
}

NodeT* BST  :: getRoot(){
    return root;
}

string BST :: searchRec(NodeT* ptr, string key){
    if(!ptr)
    	return "NA";
    else{
        if(key == ptr->key)
        return ptr->meaning;
        else if(key < ptr->key)
        return searchRec(ptr->lchild, key);
        else
        return searchRec(ptr->rchild, key);
    }
}

NodeT* BST :: insert(NodeT* ptr, string key, string meaning){
    if(!ptr){
        ptr = new NodeT;
        ptr->key = key;
        ptr->meaning = meaning;
        ptr->lchild = ptr->rchild = NULL;
        if(!root)
        root = ptr;
        return ptr;
    }
    else{
        if(key < ptr->key)
            ptr->lchild = insert(ptr->lchild, key, meaning);
        else if(key > ptr->key)
            ptr->rchild = insert(ptr->rchild, key, meaning);
        return ptr;
    }
}

NodeT* BST :: deletion(NodeT* p, string key){
    NodeT* q = NULL;
    if(!p) return NULL;

    if(key < p->key) p->lchild = deletion(p->lchild, key);
    else if(key > p->key) p->rchild = deletion(p->rchild, key);
    else{
        if(!p->lchild && !p->rchild){
            if(p == root) root = NULL;
            delete p;
            return NULL;
        }
        else{
            if(height(p->lchild) > height(p->rchild)){
                q = InPre(p->lchild);
                p->key = q->key;
                p->meaning = q->meaning;
                p->lchild = deletion(p->lchild, q->key);
            }
            else{
                q = InSucc(p->rchild);
                p->key = q->key;
                p->meaning = q->meaning;
                p->rchild = deletion(p->rchild, q->key);
            }
        }
    }
    return p;
}

NodeT* BST :: InPre(NodeT* p){
    if(!p)
        return NULL;
    else{
        while(p->rchild){
            p = p->rchild;
        }
        return p;
    }
}

NodeT* BST :: InSucc(NodeT* p){
    if(!p)
        return NULL;
    else{
        while(p->lchild){
            p = p->lchild;
        }
        return p;
    }
}

int BST :: height(NodeT* p){
    if(!p)
        return -1;
    else{
        int x = height(p->lchild);
        int y = height(p->rchild);
        return (x > y) ? x+1 : y+1;
    }
}

int BST :: compCount(NodeT* ptr, string key){
	int count = 0;
    while(ptr){
        if(key == ptr->key){
            count++;
            break;
        }

        else if(key < ptr->key){
            count++;
            ptr = ptr->lchild;
        }

        else{
            count++;
            ptr = ptr->rchild;
        }
    }
    return count;
}

int main(){
    BST dict;
    char choice = 'y';
	while(choice != 'n' && choice == 'y'){

        int menu=0;
        cout<<"MENU:\n1. Add word\n2. Update word\n3. Display words in ascending order\n4. Display words in descending order\n5. Comparison count\n6. Search key\n7. Delete word"<<endl;
        cout<<"Enter menu: ";
        cin>>menu;
        switch(menu){
            case 1:{
                //Add word
                string key, meaning;
                cout<<"Enter key: ";
                cin>>key;
                cout<<endl;
                cout<<"Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dict.insert(dict.getRoot(), key, meaning);
                cout<<endl;
                break;
            }
            case 2:{
                //Update word
                string key;
                cout<<"Enter key to be updated: ";
                cin>>key;
                dict.updateKey(dict.getRoot(), key);
                break;
            }
            case 3:{
                //Ascending order
                cout<<"Keys in ascending order"<<endl;
                dict.ascOrder(dict.getRoot());
                break;
            }
            case 4:{
                //Descending order
                cout<<"Keys in descending order"<<endl;
                dict.desOrder(dict.getRoot());
                break;
            }
            case 5:{
                //Comparison count
                int count = 0;
                string key;
                cout<<"Enter key: ";
                cin>>key;
                count = dict.compCount(dict.getRoot(), key);
                cout<<"Number of comparisons for "<<key<<": "<<count<<endl;
                break;
            }
            case 6:{
                //Search key
                string key, meaning;
                cout<<"Enter key to search: ";
                cin>>key;
                meaning = dict.searchRec(dict.getRoot(), key);
                if(meaning == "NA"){
                    cout<<"key not found"<<endl;
                }
                else{
                    cout<<"key- "<<key<<" : meaning- "<<meaning<<endl;
                }
                cout<<endl;
                break;
            }
            case 7:{
                //Delete word
                string key;
                cout<<"Enter key: ";
                cin>>key;
                dict.deletion(dict.getRoot(), key);
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
Output:
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 1
Enter key: ajinkya

Enter meaning: human


Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 1
Enter key: aeroplane

Enter meaning: vehicle


Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 1
Enter key: mathematics

Enter meaning: subject


Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 1
Enter key: bat

Enter meaning: toy


Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 3
Keys in ascending order
(Key: aeroplane ->meaning: vehicle)
(Key: ajinkya ->meaning: human)
(Key: bat ->meaning: toy)
(Key: mathematics ->meaning: subject)

Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 4
Keys in descending order
(Key: mathematics ->meaning: subject)
(Key: bat ->meaning: toy)
(Key: ajinkya ->meaning: human)
(Key: aeroplane ->meaning: vehicle)

Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 5
Enter key: mathematics
Number of comparisons for mathematics: 2

Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 6
Enter key to search: bat
key- bat : meaning- toy


Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 7
Enter key: aeroplane

Do want to continue:?('y'/'n')-> y

------------------------------------------------
MENU:
1. Add word
2. Update word
3. Display words in ascending order
4. Display words in descending order
5. Comparison count
6. Search key
7. Delete word
Enter menu: 3
Keys in ascending order
(Key: ajinkya ->meaning: human)
(Key: bat ->meaning: toy)
(Key: mathematics ->meaning: subject)

Do want to continue:?('y'/'n')-> n

------------------------------------------------
*/
