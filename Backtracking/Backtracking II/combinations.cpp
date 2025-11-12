#include <bits/stdc++.h>
using namespace std;

void combineHelper(int n, int k, int start, vector<int>& temp, vector<vector<int>>& res) {
    // Base case: if we have k numbers
    if (temp.size() == k) {
        res.push_back(temp);
        return;
    }
    
    // Try all possible numbers from start to n
    for (int i = start; i <= n; i++) {
        // Include current number
        temp.push_back(i);
        // Recur with next number
        combineHelper(n, k, i + 1, temp, res);
        // Backtrack by removing current number
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    combineHelper(n, k, 1, temp, res);
    return res;
}

/*
Logic: Generate all possible k-sized combinations from numbers 1 to n
1. Start with empty combination
2. For each position, try numbers from start to n
3. After adding k numbers, add combination to result
4. Backtrack by removing last number to try next possibility

Time Complexity: O(C(n,k)) - number of possible combinations
Space Complexity: O(k) for recursion stack and temporary combination
where C(n,k) is binomial coefficient = n!/(k!(n-k)!)
*/

// Helper function to print combinations
void printCombinations(const vector<vector<int>>& combinations) {
    for (const auto& combo : combinations) {
        cout << "{";
        for (int i = 0; i < combo.size(); i++) {
            cout << combo[i];
            if (i < combo.size() - 1) cout << ",";
        }
        cout << "} ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: n=4, k=2
    cout << "Test Case 1: n=4, k=2" << endl;
    int n1 = 4, k1 = 2;
    cout << "Combinations: ";
    auto result1 = combine(n1, k1);
    printCombinations(result1);
    
    // Test Case 2: n=3, k=3
    cout << "\nTest Case 2: n=3, k=3" << endl;
    int n2 = 3, k2 = 3;
    cout << "Combinations: ";
    auto result2 = combine(n2, k2);
    printCombinations(result2);
    
    // Test Case 3: n=5, k=1
    cout << "\nTest Case 3: n=5, k=1" << endl;
    int n3 = 5, k3 = 1;
    cout << "Combinations: ";
    auto result3 = combine(n3, k3);
    printCombinations(result3);
    
    return 0;
}