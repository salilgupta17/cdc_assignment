#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

// Brute force: count nodes then traverse half
Node* midListBF(Node* head) {
    int c=0; Node* cur = head;
    while(cur){ c++; cur=cur->next;}
    int mid = c/2;
    cur = head;
    for (int i=0; i<mid; i++) cur=cur->next;
    return cur;
}

// Optimized: two pointers slow-fast
Node* midListOpt(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    cout << midListOpt(head)->val << "\n";
    return 0;
}

/*
Logic: BF counts length, Opt uses fast-slow pointers.  
Time: O(n), Space: O(1)
*/