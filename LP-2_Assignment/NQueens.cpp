#include <iostream>
#include <vector>

using namespace std;

bool checkConstraint(vector<vector<int>>& board, int row, int col){
    // Check its row safety.

    for(int i = 0; i < col; i++){
        if(board[row][i]) return false;
    }

    // Check upward diagonal

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]) return false;
    }

    // Check downward diagonal

    for(int i = row, j = col; i < board.size() && j >= 0; i++, j--){
        if(board[i][j]) return false;
    }

    // Here constraint is satisfied
    
    return true;
}

bool checkConstraintNBound(vector<vector<int>>& board, int row, int col, vector<bool>& rowStatus, vector<bool>& normalDiagonal, vector<bool>& reverseDiagonal){
    if(rowStatus[row] || normalDiagonal[row + col] || reverseDiagonal[row - col + board.size() - 1])
        return false;
    
    return true;
}

bool nqueens(vector<vector<int>>& board, int col){
    if(col == board.size()){
        return true;

    }else{
        for(int row = 0; row < board.size(); row++){

            if(checkConstraint(board, row, col)){
                
                board[row][col] = 1;

                if(nqueens(board, col + 1))
                    return true;
                
                board[row][col] = 0;
            }
        }

        // Queen cannot be placed in the curren col
        return false;
    }
}

bool nqueensBranchNBound(vector<vector<int>>& board, int col, vector<bool>& rowStatus, vector<bool>& normalDiagonal, vector<bool>& reverseDiagonal){
    if(col == board.size()){
        return true;

    }else{
        for(int row = 0; row < board.size(); row++){

            if(checkConstraintNBound(board, row, col, rowStatus, normalDiagonal, reverseDiagonal)){
                rowStatus[row] = true;
                normalDiagonal[row + col] = true;
                reverseDiagonal[row - col + board.size() - 1] = true;
                board[row][col] = 1;

                if(nqueensBranchNBound(board, col + 1, rowStatus, normalDiagonal, reverseDiagonal))
                    return true;
                
                
                board[row][col] = 0;
                rowStatus[row] = false;
                normalDiagonal[row + col] = false;
                reverseDiagonal[row - col + board.size() - 1] = false;
            }
        }

        // Queen cannot be placed in the curren col
        return false;
    }
}

void showBoard(vector<vector<int>>& board){
    cout<<endl;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {

    int nodes = 0;
    cout<<"Enter number chess board size: ";
    cin>>nodes;

    vector<vector<int>> board(nodes, vector<int> (nodes, 0));

    vector<bool> rowStatus(nodes, false);
    vector<bool> normalDiagonal(2*nodes - 1, false);
    vector<bool> reverseDiagonal(2*nodes - 1, false);

    /*
    if(nqueens(board, 0)){
        cout<<"Solutions exists"<<endl;
        showBoard(board);
    }else{
        cout<<"Solutions does'nt exists"<<endl;
    }
    */

    if(nqueensBranchNBound(board, 0, rowStatus, normalDiagonal, reverseDiagonal)){
        cout<<"Solutions exists"<<endl;
        showBoard(board);
    }else{
        cout<<"Solutions does'nt exists"<<endl;
    }
    return 0;
}
