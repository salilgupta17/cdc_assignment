#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end;
};

// Sort activities by end time
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int activitySelection(vector<Activity>& activities) {
    // Sort by finish time
    sort(activities.begin(), activities.end(), compare);
    
    int count = 1;  // First activity is always selected
    int lastFinish = activities[0].end;
    
    // Consider rest of activities
    for (int i = 1; i < activities.size(); i++) {
        // If current activity starts after last selected activity ends
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].end;
        }
    }
    return count;
}

/*
Logic: Maximum number of non-overlapping activities
1. Sort all activities by finish time
2. Select first activity (earliest finish)
3. For remaining activities:
   - If start time >= last selected activity's finish time
   - Select it and update last finish time
4. Return count of selected activities

Why Greedy Works:
- Sorting by finish time ensures we always have maximum time for remaining activities
- Each selection is locally optimal (earliest finish)
- Local optimal choices lead to global optimal solution

Time Complexity: O(n log n) for sorting
Space Complexity: O(1) excluding input array
*/

void printActivities(const vector<Activity>& activities) {
    for (const auto& act : activities) {
        cout << "(" << act.start << "," << act.end << ") ";
    }
    cout << endl;
}

int main() {
    // Test Case 1: Normal case
    cout << "Test Case 1:" << endl;
    vector<Activity> acts1 = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    cout << "Activities: ";
    printActivities(acts1);
    cout << "Maximum activities: " << activitySelection(acts1) << endl;
    
    // Test Case 2: All activities overlap
    cout << "\nTest Case 2:" << endl;
    vector<Activity> acts2 = {{1, 5}, {2, 6}, {3, 7}, {4, 8}};
    cout << "Activities: ";
    printActivities(acts2);
    cout << "Maximum activities: " << activitySelection(acts2) << endl;
    
    // Test Case 3: No overlap
    cout << "\nTest Case 3:" << endl;
    vector<Activity> acts3 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "Activities: ";
    printActivities(acts3);
    cout << "Maximum activities: " << activitySelection(acts3) << endl;
    
    return 0;
}