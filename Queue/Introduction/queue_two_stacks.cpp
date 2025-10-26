#include <bits/stdc++.h>
using namespace std;

class QueueUsingStacks {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }

    bool dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return false;
        s2.pop();
        return true;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;
        return s2.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Peek: " << q.peek() << "\n";
    q.dequeue();
    cout << "Peek after dequeue: " << q.peek() << "\n";
    return 0;
}

/*
Logic: Two stacks simulate queue; stack1 for enqueue, stack2 for dequeue.  
Amortized O(1) per operation.
*/