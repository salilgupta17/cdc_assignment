#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
    }
    
    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
    }
    
    // Check 3x3 sub-box
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == c) return false;
        }
    }
    
    return true;
}

bool solveSudokuUtil(vector<vector<char>>& board) {
    // Find empty cell
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                // Try placing digits 1-9
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, row, col, num)) {
                        // Place the number
                        board[row][col] = num;
                        
                        // Recur to fill rest of the board
                        if (solveSudokuUtil(board)) return true;
                        
                        // If placing num didn't lead to solution, backtrack
                        board[row][col] = '.';
                    }
                }
                // If no number can be placed, return false
                return false;
            }
        }
    }
    // All cells are filled
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuUtil(board);
}

/*
Logic: Solve Sudoku using backtracking
1. Find empty cell
2. Try placing digits 1-9 in empty cell
3. Check if placement is valid (row, column, 3x3 box)
4. If valid, recur for rest of board
5. If placement leads to invalid solution, backtrack

Time Complexity: O(9^(n*n)) worst case, where n is board size
Space Complexity: O(n*n) for recursion stack
*/

// Helper function to print Sudoku board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) cout << "- - - - - - - - - - - -" << endl;
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) cout << "| ";
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test Case 1: Solvable Sudoku
    cout << "Test Case 1: Solvable Sudoku" << endl;
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    cout << "Original board:" << endl;
    printBoard(board1);
    
    solveSudoku(board1);
    
    cout << "\nSolved board:" << endl;
    printBoard(board1);
    
    // Test Case 2: Empty board
    cout << "\nTest Case 2: Empty board" << endl;
    vector<vector<char>> board2(9, vector<char>(9, '.'));
    
    cout << "Original board:" << endl;
    printBoard(board2);
    
    solveSudoku(board2);
    
    cout << "\nSolved board:" << endl;
    printBoard(board2);
    
    return 0;
}