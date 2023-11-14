#include<iostream>
#include<vector>
using namespace std;

int calc(int ind, vector<int>& profit, vector<int>& weight, int curr_max_w, vector< vector<int> >& dp){
    if(ind < 0) return 0;

    if(dp[ind][curr_max_w] != -1) return dp[ind][curr_max_w];

    int left = 0;
    int right = 0;


    if(curr_max_w >= weight[ind])
        left = profit[ind] + calc(ind - 1, profit, weight, curr_max_w - weight[ind], dp);
    right = calc(ind - 1, profit, weight, curr_max_w, dp);

    return dp[ind][curr_max_w] = max(left, right);
}

int main(){
    vector<int> profit = {10, 20, 30};    
    vector<int> weight = {1, 1, 1};
    int w = 2;
    vector< vector<int> > dp (profit.size(), vector<int> (w + 1, -1));        
    cout<<calc(profit.size() - 1, profit, weight, w, dp);
    return 0;
}