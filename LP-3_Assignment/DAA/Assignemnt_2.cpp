#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node {
    int freq;
    char c;
    Node* left;
    Node* right;
    public:
    int getNodeFreq() {return freq;}
    char getNodeChar() {return c;}
    friend class Tree;
};

class Tree{
    Node* root;
    map<char, string> encoding;
    public:
    Tree() {root = nullptr;}
    void create(vector<int>, vector<char>);
    void encode(Node*, string&);
    void printEncoding();
    void VLR(Node*);
    void showTree();
};

void Tree :: create(vector<int> freqs, vector<char> items){

    auto cmp = [](Node* node1, Node* node2){
        // Returns true if swap required
        return node1->getNodeFreq() > node2->getNodeFreq();
    };

    priority_queue<Node*, vector<Node*>, decltype(cmp)> minHeap(cmp);

    for(int i = 0; i < freqs.size(); i++){
        Node* newNode = new Node;
        newNode->freq = freqs[i];
        newNode->c = items[i];
        newNode->left = newNode->right = nullptr;
        minHeap.push(newNode);
    }

    while(minHeap.size() != 1){
        Node* node1 = minHeap.top();
        minHeap.pop();
        Node* node2 = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node;
        newNode->freq = node1->freq + node2->freq;
        newNode->left = node1;
        newNode->right = node2;
        minHeap.push(newNode);
    }

    root = minHeap.top();
    minHeap.pop();

    string huff_code = "";
    encode(root, huff_code);
    return;
}

void Tree :: VLR(Node* ptr){
    if(ptr){
    cout<<ptr->freq<<" ";
    VLR(ptr->left);
    VLR(ptr->right);
    }
}

void Tree :: showTree(){
    VLR(root);
}

void Tree :: encode(Node* node, string& code){
    if(!node->left && !node->right) encoding[node->c] = code;
    else{
        code.push_back('0');
        encode(node->left, code);
        code.pop_back();
        code.push_back('1');
        encode(node->right, code);
        code.pop_back();
    }
}

void Tree :: printEncoding(){
    for(auto pr: encoding){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}



int main(){
    vector<int> freqs = { 5, 1, 6, 3};
    vector<char> items = { 'a', 'b', 'c', 'd'};
    Tree huffman;
    huffman.create(freqs, items);
    // huffman.showTree();
    huffman.printEncoding();
    return 0;
}
