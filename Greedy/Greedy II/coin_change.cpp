#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    // Sort coins in descending order
    sort(coins.rbegin(), coins.rend());
    
    int totalCoins = 0;
    
    // Try each coin denomination from largest to smallest
    for (int coin : coins) {
        if (amount >= coin) {
            // Use as many of current coin as possible
            int coinsUsed = amount / coin;
            totalCoins += coinsUsed;
            amount -= (coinsUsed * coin);
        }
        
        // Early return if amount becomes 0
        if (amount == 0) break;
    }
    
    // Return -1 if amount couldn't be made
    return amount == 0 ? totalCoins : -1;
}

/*
Logic: Make amount using minimum number of coins
1. Sort coins in descending order
2. For each coin denomination:
   - Use as many coins as possible
   - Update remaining amount
3. Continue until amount becomes 0

Why Greedy Works (for standard coin systems):
- Larger denominations are always optimal to use first
- Each coin is multiple of smaller ones
- No combination of smaller coins is better than larger coin

Note: This greedy approach works only for canonical coin systems
(like US/Indian currency). For arbitrary coin values, dynamic
programming should be used.

Time Complexity: O(n log n) for sorting + O(n) for coin selection
Space Complexity: O(1) excluding input array
*/

void printSolution(const vector<int>& coins, int amount, int result) {
    cout << "Coins available: ";
    for (int coin : coins) cout << coin << " ";
    cout << "\nAmount: " << amount << endl;
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "Cannot make amount with given coins" << endl;
    }
}

int main() {
    // Test Case 1: Standard US coins
    cout << "Test Case 1:" << endl;
    vector<int> coins1 = {25, 10, 5, 1};  // Quarter, dime, nickel, penny
    int amount1 = 67;
    int result1 = minCoins(coins1, amount1);
    printSolution(coins1, amount1, result1);
    
    // Test Case 2: Indian currency example
    cout << "\nTest Case 2:" << endl;
    vector<int> coins2 = {10, 5, 2, 1};
    int amount2 = 43;
    int result2 = minCoins(coins2, amount2);
    printSolution(coins2, amount2, result2);
    
    // Test Case 3: Impossible amount
    cout << "\nTest Case 3:" << endl;
    vector<int> coins3 = {5, 2};
    int amount3 = 3;
    int result3 = minCoins(coins3, amount3);
    printSolution(coins3, amount3, result3);
    
    // Test Case 4: Zero amount
    cout << "\nTest Case 4:" << endl;
    vector<int> coins4 = {1, 2, 5};
    int amount4 = 0;
    int result4 = minCoins(coins4, amount4);
    printSolution(coins4, amount4, result4);
    
    return 0;
}