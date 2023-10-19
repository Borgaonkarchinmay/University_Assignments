#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;
class NQueens
{
    int n;

public:
    NQueens(int n)
    {
        this->n = n;
    }
    bool isSafe(vector<string> board, int row, int col);
    void solve(vector<string> &board, vector<vector<string>> &ans, int col);
};

bool NQueens::isSafe(vector<string> board, int row, int col)
{
    // horizontally checking
    rep(i, 0, n)
    {
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }

    // vertically checking
    rep(i, 0, n)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    int r = row;
    // upper right
    for (int c = col; c < n, r >= 0; c++, r--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }
    // upper left
    r = row;
    for (int c = col; c >= 0, r >= 0; c--, r--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }
    // lower right
    r = row;
    for (int c = col; c < n, r < n; c++, r++)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    // lower left
    r = row;
    for (int c = col; c >= 0, r < n; c--, r++)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void NQueens::solve(vector<string> &board, vector<vector<string>> &ans, int col)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    rep(row, 0, n)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(board, ans, col + 1);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "Enter N:" << endl;
    cin >> n;
    NQueens nq(n);
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    rep(i,0,n)
    {
        board[i] = s;
    }
    nq.solve(board, ans, 1);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[0].size())
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
}