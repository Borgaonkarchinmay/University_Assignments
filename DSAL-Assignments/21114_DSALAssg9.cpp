#include<iostream>
using namespace std;

class Heap{
    int* arr;
    int eleCount;
    public:
    Heap(){arr = nullptr; eleCount = 0;}
    Heap(int n){arr = nullptr; eleCount = n; arr = new int[eleCount + 1];}
    int getChild(int, int);
    void swap(int, int);
    void deletion(int);
    void heapSort();
    void displayArr();
    void generateHeap();
};


int Heap :: getChild(int parent, int size){
    if(2*parent <= size){
        if((2*parent + 1) <= size){
            //both nodes
            if(arr[2*parent + 1] > arr[2*parent])
                return 2*parent + 1;
            else
                return 2*parent;
        }
        //only one node
        else
            return 2*parent;
    }
    //leaf node
    else
        return -1;
}

void Heap ::swap(int i1, int i2){
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void Heap :: deletion(int n){
    swap(1, n);
    cout<<"Swapping "<<arr[1]<<" and "<<arr[n]<<endl;
    n--;
    int p = 1;
    int c = getChild(p, n);
    while(2*p <= n && arr[p] < arr[c]){
        swap(p, c);
        cout<<"Swapping "<<arr[p]<<" and "<<arr[c]<<endl;
        p = c;
        c = getChild(p, n);
    }
}

void Heap :: heapSort(){
    int size = eleCount;
    for(int i = size; i > 0; i--){
        deletion(i);
    }
}

void Heap :: displayArr(){
    for(int i = 1; i <=eleCount; i++){
        cout<<arr[i]<<", ";
    }
}

void Heap :: generateHeap(){
    int ele;
    for(int i = 1; i <= eleCount; i++){
        cout<<"enter element: ";
        cin>>ele;
        arr[i] = ele;
        int ind = i, p = i/2, temp;
        while(p > 0 && ele > arr[p]){
            swap(p, ind);
            cout<<"Swaping "<<p<<" and "<<ind<<endl;
            ind = p;
            p = p/2;
        }
    }
}

int main(){
    int eleNo = 0;
    cout<<"Enter number of elements: ";
    cin>>eleNo;
    Heap obj(eleNo);
    obj.generateHeap();
    obj.displayArr();
    obj.heapSort();
    cout<<endl;
    cout<<"Sorted elements are: "<<endl;
    obj.displayArr();
    
    return 0;
}

/*
Output:
Enter number of elements: 7
enter element: 12
enter element: 1
enter element: 7
enter element: 56
Swaping 2 and 4
Swaping 1 and 2
enter element: 68
Swaping 2 and 5
Swaping 1 and 2
enter element: 16
Swaping 3 and 6
enter element: 84
Swaping 3 and 7
Swaping 1 and 3
84, 56, 68, 1, 12, 7, 16, Swapping 16 and 84
Swapping 68 and 16
Swapping 7 and 68
Swapping 56 and 7
Swapping 12 and 7
Swapping 7 and 56
Swapping 16 and 7
Swapping 1 and 16
Swapping 12 and 1
Swapping 7 and 12
Swapping 1 and 7
Swapping 1 and 1

1, 7, 12, 16, 56, 68, 84, 
*/