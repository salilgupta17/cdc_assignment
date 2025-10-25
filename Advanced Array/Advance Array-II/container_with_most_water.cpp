#include <bits/stdc++.h>
using namespace std;

// Brute force: check all pairs for max water area
int maxWaterBF(const vector<int>& height) {
    int maxArea = 0;
    int n = height.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

// Optimized: two pointers moving inward
int maxWaterOpt(const vector<int>& height) {
    int left = 0, right = (int)height.size() - 1;
    int maxArea = 0;
    while (left < right) {
        maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) left++;
        else right--;
    }
    return maxArea;
}

int main() {
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << "BF: " << maxWaterBF(h) << "\n";
    cout << "Opt: " << maxWaterOpt(h) << "\n";
    return 0;
}

/*
Logic: BF tries all pairs O(n^2),  
Opt uses two pointers scan O(n) time, O(1) space.
*/