#include <bits/stdc++.h>
using namespace std;

class MinStackBF {
    stack<int> s;
    stack<int> minS;
public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top()) minS.push(x);
    }
    void pop() {
        if (s.top() == minS.top()) minS.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return minS.top();
    }
};

class MinStackOpt {
    stack<int> s;
public:
    void push(int x) {
        s.push(x);
    }
    void pop() {
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        stack<int> temp;
        int minVal = INT_MAX;
        while (!s.empty()) {
            minVal = min(minVal, s.top());
            temp.push(s.top());
            s.pop();
        }
        while (!temp.empty()) {
            s.push(temp.top()), temp.pop();
        }
        return minVal;
    }
};

int main() {
    MinStackBF s;
    s.push(3);
    s.push(5);
    cout << "Min: " << s.getMin() << "\n";
    s.push(2);
    s.push(1);
    cout << "Min: " << s.getMin() << "\n";
    s.pop();
    cout << "Top: " << s.top() << ", Min: " << s.getMin() << "\n";

    MinStackOpt o;
    o.push(3);
    o.push(5);
    cout << "Opt Min: " << o.getMin() << "\n";
    return 0;
}

/*
Logic: BF maintains second stack with min values, O(1) retrieval.  
Opt scans entire stack for min, O(n).
Space: BF O(n), Opt O(n).
*/