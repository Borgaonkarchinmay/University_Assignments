#include <bits/stdc++.h>
using namespace std;
class Fibonacci
{
public:
    int n;
    Fibonacci(int n)
    {
        this->n = n;
    }
    int recursive(int i)
    {
        if (i <= 1)
        {
            return i;
        }
        return recursive(i - 1) + recursive(i - 2);
    }
    void iterative()
    {
        int t1 = 0;
        int t2 = 1;
        int nextTerm = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                cout << t1 << " ";
                continue;
            }
            if (i == 2)
            {
                cout << t2 << " ";
                continue;
            }
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            cout << nextTerm << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter N:" << endl;
    cin >> n;
    Fibonacci fb(n);
    cout << "Using Iteration fibonacci series: " << endl;
    fb.iterative();
    cout << "Using Recursion fibonacci series: " << endl;
    int i = 0;
    while (i < n)
    {
        cout << fb.recursive(i) << " ";
        i++;
    }
    cout << endl;

    return 0;
}

/*
    Iterative Approach :
        Time Complexity :- O(N)
        Space Complexity :- O(1)
    Recursive Approach :
        Time Complexity :- O(2^N) --> Exponential Since on function makes recursive call to two more functions
        Space Complexity :- O(N) --> Max depth of recursion tree is N
*/

/*
    Input --> 
    Enter N:
    5
    Using Iteration fibonacci series:
    0 1 1 2 3
    Using Recursion fibonacci series:
    0 1 1 2 3

*/
