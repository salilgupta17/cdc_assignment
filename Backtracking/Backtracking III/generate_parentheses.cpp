#include <bits/stdc++.h>
using namespace std;

void generateParenthesesHelper(int open, int close, int n, string curr, vector<string>& res) {
    // Base case: if current string length equals 2*n
    if (curr.size() == 2 * n) {
        res.push_back(curr);
        return;
    }
    
    // Add opening bracket if count is less than n
    if (open < n) {
        generateParenthesesHelper(open + 1, close, n, curr + "(", res);
    }
    
    // Add closing bracket if its count is less than opening bracket count
    if (close < open) {
        generateParenthesesHelper(open, close + 1, n, curr + ")", res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateParenthesesHelper(0, 0, n, "", res);
    return res;
}

/*
Logic: Generate valid parentheses combinations using backtracking
1. Keep track of count of opening and closing brackets
2. Can add opening bracket if count < n
3. Can add closing bracket if its count < opening bracket count
4. When string length = 2*n, we have a valid combination

Key Rules:
- Number of '(' should never exceed n
- Number of ')' should never exceed number of '('
- Total length should be 2*n

Time Complexity: O(4^n/sqrt(n)) - nth Catalan number
Space Complexity: O(n) for recursion stack
*/

int main() {
    // Test Case 1: n = 3
    cout << "Test Case 1: n = 3" << endl;
    int n1 = 3;
    vector<string> result1 = generateParenthesis(n1);
    cout << "All valid combinations:" << endl;
    for (const string& s : result1) {
        cout << s << " ";
    }
    cout << endl;
    
    // Test Case 2: n = 2
    cout << "\nTest Case 2: n = 2" << endl;
    int n2 = 2;
    vector<string> result2 = generateParenthesis(n2);
    cout << "All valid combinations:" << endl;
    for (const string& s : result2) {
        cout << s << " ";
    }
    cout << endl;
    
    // Test Case 3: n = 1
    cout << "\nTest Case 3: n = 1" << endl;
    int n3 = 1;
    vector<string> result3 = generateParenthesis(n3);
    cout << "All valid combinations:" << endl;
    for (const string& s : result3) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}