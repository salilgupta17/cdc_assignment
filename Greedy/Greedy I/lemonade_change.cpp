#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    // Keep track of 5$ and 10$ bills (no need to track 20$)
    int five = 0, ten = 0;
    
    for (int bill : bills) {
        if (bill == 5) {
            // No change needed for 5$
            five++;
        }
        else if (bill == 10) {
            // Need one 5$ bill for change
            if (five == 0) return false;
            five--;
            ten++;
        }
        else { // bill is 20$
            // Try to use 10$ + 5$ first (greedy)
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            }
            // If not possible, use three 5$ bills
            else if (five >= 3) {
                five -= 3;
            }
            else {
                return false;
            }
        }
    }
    
    return true;
}

/*
Logic: Greedy approach for making change
1. For 5$ bills: Just store them
2. For 10$ bills: Need one 5$ bill
3. For 20$ bills: Prefer 10$ + 5$ over three 5$
   (Keep smaller bills for future transactions)

Key Points:
- Always give change using larger bills first
- Track only 5$ and 10$ bills (20$ bills can't be used)
- Return false if we can't make change at any point

Time Complexity: O(n) where n is number of bills
Space Complexity: O(1) as we only track two variables
*/

int main() {
    // Test Case 1: Simple successful case
    cout << "Test Case 1:" << endl;
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << "Bills: ";
    for (int x : bills1) cout << x << " ";
    cout << "\nCan make change? " << (lemonadeChange(bills1) ? "Yes" : "No") << endl;
    
    // Test Case 2: Impossible case (no change available)
    cout << "\nTest Case 2:" << endl;
    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << "Bills: ";
    for (int x : bills2) cout << x << " ";
    cout << "\nCan make change? " << (lemonadeChange(bills2) ? "Yes" : "No") << endl;
    
    // Test Case 3: Edge case - all 5$ bills
    cout << "\nTest Case 3:" << endl;
    vector<int> bills3 = {5, 5, 5, 5, 5};
    cout << "Bills: ";
    for (int x : bills3) cout << x << " ";
    cout << "\nCan make change? " << (lemonadeChange(bills3) ? "Yes" : "No") << endl;
    
    // Test Case 4: Start with larger bill (impossible)
    cout << "\nTest Case 4:" << endl;
    vector<int> bills4 = {10, 5, 5};
    cout << "Bills: ";
    for (int x : bills4) cout << x << " ";
    cout << "\nCan make change? " << (lemonadeChange(bills4) ? "Yes" : "No") << endl;
    
    return 0;
}