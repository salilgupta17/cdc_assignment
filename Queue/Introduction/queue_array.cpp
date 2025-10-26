#include <bits/stdc++.h>
using namespace std;

class QueueBF {
    int front, rear, size;
    vector<int> arr;
public:
    QueueBF(int n): front(-1), rear(-1), size(n), arr(n) {}
    bool enqueue(int x) {
        if ((rear + 1) % size == front) return false; // Full
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
        return true;
    }
    bool dequeue() {
        if (front == -1) return false; // Empty
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
        return true;
    }
    int peek() {
        if (front == -1) return -1;
        return arr[front];
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

int main() {
    QueueBF q(5);
    q.enqueue(10);
    q.enqueue(20);
    cout << "Peek: " << q.peek() << "\n";
    q.dequeue();
    cout << "Peek after dequeue: " << q.peek() << "\n";
    return 0;
}

/*
Logic: Circular array with modulo indexing to wrap around.  
O(1) enqueue/dequeue, fixed capacity.
*/