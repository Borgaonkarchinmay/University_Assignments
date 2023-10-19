#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100
class HuffmanTreeNode{
public:
    char data;
    int freq;
    HuffmanTreeNode* left;
    HuffmanTreeNode* right;
    HuffmanTreeNode(char character,int frequency){
        data = character;
        freq = frequency;
        left = right = NULL;
    }
};

//custom comparator
class Compare{
    public: 
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b){
        return a->freq > b->freq;
    }
};

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,Compare> pq){
    while(pq.size() != 1){
        HuffmanTreeNode *left = pq.top();
        pq.pop();
        HuffmanTreeNode *right= pq.top();
        pq.pop();

        HuffmanTreeNode *node = new HuffmanTreeNode('$', left->freq + right->freq);
        node->left = left;
        node->right = right;

        pq.push(node);
    }
    return pq.top();
}

void printCodes(HuffmanTreeNode *root,vector<int> arr,int top)
{
    if(root->left){
        arr[top] = 0;
        printCodes(root->left,arr,top+1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if(!root->left && !root->right){
        cout << root->data << " ";
        for (int i = 0; i < top;i++){
            cout << arr[i];
        }
        cout << endl;
    }
}
void HuffmanCodes(vector<char> data,vector<int> freq){
    priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>, Compare> pq;
    int size = data.size();
    for (int i = 0; i < size;i++){
        HuffmanTreeNode *newNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }
    HuffmanTreeNode *root = generateTree(pq);

    vector<int> arr(MAX_SIZE);
    int top = 0;
    printCodes(root, arr, top);
}
int main(){
    int n;
    cin >> n;
    vector<char> data;
    vector<int> freq;
    char x;
    for (int i = 0; i < n;i++){
        cin >> x;
        data.push_back(x);
    }
    int y;
    for (int i = 0; i < n; i++)
    {
        cin >> y;
        freq.push_back(y);
    }
    HuffmanCodes(data, freq);
    return 0;
}

/*
    Input ->
    6
    a b c d e f
    5 9 12 13 16 45

    Output ->
    f 0
    c 100
    d 101
    a 1100
    b 1101
    e 111
*/

/*
    Complexity Analysis --> 
    Time Complexity -> O(n log(n))
    Space Complexity -> O(n)
*/
