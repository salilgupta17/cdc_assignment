#include <bits/stdc++.h>
using namespace std;

// Min heap using priority_queue with greater comparator
class MinHeap {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    void push(int x) { pq.push(x); }
    void pop() { if(!pq.empty()) pq.pop(); }
    int top() { return pq.empty() ? -1 : pq.top(); }
    bool empty() { return pq.empty(); }
};

// Max heap using default priority_queue
class MaxHeap {
    priority_queue<int> pq;
public:
    void push(int x) { pq.push(x); }
    void pop() { if(!pq.empty()) pq.pop(); }
    int top() { return pq.empty() ? -1 : pq.top(); }
    bool empty() { return pq.empty(); }
};

int main() {
    MinHeap minh;
    minh.push(5); minh.push(2); minh.push(8);
    cout << "Min top: " << minh.top() << '\n';
    minh.pop();
    cout << "Min top after pop: " << minh.top() << '\n';

    MaxHeap maxh;
    maxh.push(5); maxh.push(2); maxh.push(8);
    cout << "Max top: " << maxh.top() << '\n';
    maxh.pop();
    cout << "Max top after pop: " << maxh.top() << '\n';
    return 0;
}
