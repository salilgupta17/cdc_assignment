#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Compare items based on value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Fractional Knapsack (Greedy Approach)
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0;
    int currentWeight = 0;
    
    // Process items in sorted order
    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take whole item
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of item
            int remainingWeight = capacity - currentWeight;
            totalValue += item.value * ((double)remainingWeight / item.weight);
            break;
        }
    }
    
    return totalValue;
}

// 0/1 Knapsack (Dynamic Programming Approach for comparison)
int zeroOneKnapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i-1].weight <= w) {
                dp[i][w] = max(
                    items[i-1].value + dp[i-1][w - items[i-1].weight],
                    dp[i-1][w]
                );
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

/*
Comparison between Greedy and DP approaches:

1. Fractional Knapsack (Greedy)
   - Can take fractions of items
   - Sort by value/weight ratio
   - Always optimal for fractional case
   - Time: O(n log n)
   - Space: O(1)

2. 0/1 Knapsack (DP)
   - Must take whole items only
   - Consider all possible combinations
   - Optimal for 0/1 case
   - Time: O(n * W)
   - Space: O(n * W)

Why Greedy works for Fractional:
- Best value/weight ratio gives optimal solution
- Can take fractions, so no need to consider combinations

Why Greedy fails for 0/1:
- Cannot take fractions
- Local optimal (highest ratio) may not lead to global optimal
*/

void printItems(const vector<Item>& items) {
    cout << "Items (Value, Weight):" << endl;
    for (const auto& item : items) {
        cout << "(" << item.value << "," << item.weight << ") ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Basic case
    cout << "Test Case 1:" << endl;
    vector<Item> items1 = {
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)
    };
    int capacity1 = 50;
    printItems(items1);
    cout << "Capacity: " << capacity1 << endl;
    cout << "Fractional Knapsack Value: " << fractionalKnapsack(capacity1, items1) << endl;
    cout << "0/1 Knapsack Value: " << zeroOneKnapsack(capacity1, items1) << endl;
    
    // Test Case 2: Small capacity
    cout << "\nTest Case 2:" << endl;
    vector<Item> items2 = {
        Item(50, 10),
        Item(40, 5),
        Item(30, 15)
    };
    int capacity2 = 15;
    printItems(items2);
    cout << "Capacity: " << capacity2 << endl;
    cout << "Fractional Knapsack Value: " << fractionalKnapsack(capacity2, items2) << endl;
    cout << "0/1 Knapsack Value: " << zeroOneKnapsack(capacity2, items2) << endl;
    
    // Test Case 3: All items fit
    cout << "\nTest Case 3:" << endl;
    vector<Item> items3 = {
        Item(10, 5),
        Item(20, 10),
        Item(30, 15)
    };
    int capacity3 = 30;
    printItems(items3);
    cout << "Capacity: " << capacity3 << endl;
    cout << "Fractional Knapsack Value: " << fractionalKnapsack(capacity3, items3) << endl;
    cout << "0/1 Knapsack Value: " << zeroOneKnapsack(capacity3, items3) << endl;
    
    return 0;
}