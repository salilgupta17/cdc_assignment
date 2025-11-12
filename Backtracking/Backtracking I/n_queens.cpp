#include <bits/stdc++.h>
using namespace std;

bool isSafeQueen(int row, int col, vector<string>& board, int n) {
    // Check column
    for (int i = 0; i < row; i++) 
        if (board[i][col] == 'Q') return false;

    // Check upper left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j] == 'Q') return false;

    // Check upper right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) 
        if (board[i][j] == 'Q') return false;

    return true;
}

void solveNQueens(int row, int n, vector<string>& board, vector<vector<string>>& res) {
    // Base case: all queens are placed
    if (row == n) {
        res.push_back(board);
        return;
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (isSafeQueen(row, col, board, n)) {
            board[row][col] = 'Q';  // Place queen
            solveNQueens(row + 1, n, board, res);  // Recur for next row
            board[row][col] = '.';   // Backtrack
        }
    }
}

vector<vector<string>> nQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));  // Initialize empty board
    solveNQueens(0, n, board, res);
    return res;
}

/*
Logic: Place N queens on NxN board such that no queen attacks another
1. Try placing queen in each column of current row
2. Check if placement is safe (no attacks in column and diagonals)
3. If safe, place queen and recur for next row
4. If no solution found, backtrack by removing queen

Time Complexity: O(N!) - N choices for first row, N-1 for second, etc.
Space Complexity: O(N²) for board + recursion stack
*/

void printBoard(const vector<string>& board) {
    for (const string& row : board) {
        cout << row << endl;
    }
}

int main() {
    // Test Case 1: 4-Queens
    cout << "Test Case 1: 4-Queens Problem" << endl;
    int n1 = 4;
    auto solutions1 = nQueens(n1);
    cout << "Number of solutions: " << solutions1.size() << endl;
    cout << "\nFirst solution:" << endl;
    if (!solutions1.empty()) {
        printBoard(solutions1[0]);
    }
    
    // Test Case 2: 8-Queens (first few solutions)
    cout << "\nTest Case 2: 8-Queens Problem" << endl;
    int n2 = 8;
    auto solutions2 = nQueens(n2);
    cout << "Number of solutions: " << solutions2.size() << endl;
    cout << "\nFirst solution:" << endl;
    if (!solutions2.empty()) {
        printBoard(solutions2[0]);
    }
    
    // Test Case 3: 3-Queens (no solution)
    cout << "\nTest Case 3: 3-Queens Problem" << endl;
    int n3 = 3;
    auto solutions3 = nQueens(n3);
    cout << "Number of solutions: " << solutions3.size() << endl;
    if (solutions3.empty()) {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}