#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& greed, vector<int>& cookies) {
    // Sort both arrays to apply greedy approach
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());
    
    int satisfied = 0;
    int childIndex = 0, cookieIndex = 0;
    
    // Try to satisfy each child with smallest possible cookie
    while (childIndex < greed.size() && cookieIndex < cookies.size()) {
        if (cookies[cookieIndex] >= greed[childIndex]) {
            satisfied++;      // Child is satisfied
            childIndex++;    // Move to next child
        }
        cookieIndex++;       // Try next cookie
    }
    
    return satisfied;
}

/*
Logic: Assign cookies to children using greedy approach
1. Sort both arrays to ensure optimal matching
2. Try to satisfy each child with smallest possible cookie
3. If current cookie can satisfy current child, give it
4. If not, try next cookie
5. Count number of satisfied children

Time Complexity: O(nlogn) due to sorting
Space Complexity: O(1) as we sort in-place
*/

int main() {
    // Test Case 1: Normal case
    cout << "Test Case 1:" << endl;
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << "Greed factors: ";
    for (int x : g1) cout << x << " ";
    cout << "\nCookie sizes: ";
    for (int x : s1) cout << x << " ";
    cout << "\nMaximum satisfied children: " << findContentChildren(g1, s1) << endl;
    
    // Test Case 2: All children can be satisfied
    cout << "\nTest Case 2:" << endl;
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << "Greed factors: ";
    for (int x : g2) cout << x << " ";
    cout << "\nCookie sizes: ";
    for (int x : s2) cout << x << " ";
    cout << "\nMaximum satisfied children: " << findContentChildren(g2, s2) << endl;
    
    // Test Case 3: No child can be satisfied
    cout << "\nTest Case 3:" << endl;
    vector<int> g3 = {2, 3};
    vector<int> s3 = {1, 1};
    cout << "Greed factors: ";
    for (int x : g3) cout << x << " ";
    cout << "\nCookie sizes: ";
    for (int x : s3) cout << x << " ";
    cout << "\nMaximum satisfied children: " << findContentChildren(g3, s3) << endl;
    
    return 0;
}