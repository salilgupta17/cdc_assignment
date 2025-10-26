#include <bits/stdc++.h>
using namespace std;

class StackBF {
    vector<int> arr;
    int top;
public:
    StackBF(int size): top(-1) {
        arr.resize(size);
    }
    bool push(int x) {
        if(top == (int)arr.size()-1) return false; // Overflow
        arr[++top] = x;
        return true;
    }
    bool pop() {
        if(top == -1) return false; // Underflow
        top--;
        return true;
    }
    int peek() {
        if(top == -1) return -1;
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};

class StackOpt {
    vector<int> arr;
public:
    void push(int x) {
        arr.push_back(x);
    }
    bool pop() {
        if(arr.empty()) return false;
        arr.pop_back();
        return true;
    }
    int peek() {
        if(arr.empty()) return -1;
        return arr.back();
    }
    bool isEmpty() {
        return arr.empty();
    }
};

int main() {
    StackBF s1(5);
    s1.push(10);
    s1.push(20);
    cout << "StackBF peek: " << s1.peek() << "\n";
    s1.pop();
    cout << "StackBF peek after pop: " << s1.peek() << "\n";

    StackOpt s2;
    s2.push(100);
    s2.push(200);
    cout << "StackOpt peek: " << s2.peek() << "\n";
    s2.pop();
    cout << "StackOpt peek after pop: " << s2.peek() << "\n";
    return 0;
}

/*
Logic: BF uses fixed size array with tracking index.  
Opt uses dynamic vector for flexible size.  
Time: O(1) for all operations; Space: O(n).
*/