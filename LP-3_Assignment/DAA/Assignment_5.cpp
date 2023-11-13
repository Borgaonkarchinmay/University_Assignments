#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int partition(vector<int>& arr, int lb, int ub){
    // int pivotIndex = lb + rand()%(ub - lb + 1);
    // int temp = arr[pivotIndex];
    // arr[pivotIndex] = arr[ub];
    // arr[ub] = temp;
    // int pivot = arr[ub];
    
    int pivot = arr[ub];
    int i = lb, j = ub;

    while(i < j){
        while(i < ub && arr[i] < pivot) i++;
        
        while(j > lb && arr[j] >= pivot) j--;

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i];
    arr[i] = pivot;
    arr[ub] = temp;

    return i;
    
}

void quickSort(vector<int>& arr, int lb, int ub){
    if(lb < ub){
        int partitionIndex = partition(arr, lb, ub);
        quickSort(arr, lb, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, ub);
    }
}

int main(){
    vector<int> arr = {10,7,8,9,1,5, 15, 16, 16, 10}; 
    quickSort(arr, 0, arr.size() - 1);
    for(auto ele : arr) cout<<ele<<" "<<endl;
    return 0;
}