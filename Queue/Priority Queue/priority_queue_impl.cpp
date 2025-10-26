#include <bits/stdc++.h>
using namespace std;

// Brute force: Using unsorted array (or vector)
class PriorityQueueBF {
    vector<int> arr;
public:
    void push(int x) {
        arr.push_back(x);
    }
    void pop() {
        if (arr.empty()) return;
        int maxIdx = 0;
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }
        arr.erase(arr.begin() + maxIdx);
    }
    int top() {
        if (arr.empty()) return -1;
        return *max_element(arr.begin(), arr.end());
    }
    bool empty() {
        return arr.empty();
    }
};

// Optimized: Using binary heap (priority_queue STL)
class PriorityQueueOpt {
    priority_queue<int> pq; // max heap by default
public:
    void push(int x) {
        pq.push(x);
    }
    void pop() {
        if (!pq.empty()) pq.pop();
    }
    int top() {
        if (pq.empty()) return -1;
        return pq.top();
    }
    bool empty() {
        return pq.empty();
    }
};

int main() {
    PriorityQueueBF bf;
    bf.push(3); bf.push(1); bf.push(4);
    cout << "BF top: " << bf.top() << '\n';
    bf.pop();
    cout << "BF top after pop: " << bf.top() << '\n';

    PriorityQueueOpt opt;
    opt.push(3); opt.push(1); opt.push(4);
    cout << "Opt top: " << opt.top() << '\n';
    opt.pop();
    cout << "Opt top after pop: " << opt.top() << '\n';
    return 0;
}
