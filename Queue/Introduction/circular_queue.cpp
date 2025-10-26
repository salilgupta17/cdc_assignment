#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int front, rear, size;
    vector<int> arr;
public:
    CircularQueue(int n): front(-1), rear(-1), size(n), arr(n) {}

    bool isFull() {
        return ((rear + 1) % size) == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool enqueue(int x) {
        if (isFull()) return false;
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
        return true;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Peek: " << q.peek() << "\n";
    q.dequeue();
    q.enqueue(4);
    cout << "Peek after wrap: " << q.peek() << "\n";
    return 0;
}

/*
Logic: Extends simple queue allowing wrap-around of rear pointer.  
Prevents wasted space in static array queue.
*/