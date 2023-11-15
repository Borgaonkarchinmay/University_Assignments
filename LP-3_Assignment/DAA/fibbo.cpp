#include<iostream>
#include<vector>

using namespace std;

int fibo(int n){
    if(n == 1) return 0;
    if(n == 2) return 1;
    
    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    cout<<fibo(9)<<endl;
    int fibo1 = 0;
    int fibo2 = 1;
    int fibon = 0;
    int itr = 3;
    int n = 7;
    while(itr <= n){
        fibon = fibo1 + fibo2;
        fibo1 = fibo2;
        fibo2 = fibon;

        itr++;
    }   

    cout<<fibon;
    return 0;
}
