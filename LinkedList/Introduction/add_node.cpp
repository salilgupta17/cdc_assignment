#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

// Brute force: traverse and insert at position with new node
Node* addNodeBF(Node* head, int pos, int val) {
    Node* newNode = new Node(val);
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* cur = head;
    for (int i=0; cur && i < pos-1; i++) cur = cur->next;
    if (!cur) return head;
    newNode->next = cur->next;
    cur->next = newNode;
    return head;
}

// Optimized: Same, no faster method for singly linked list insert
Node* addNodeOpt(Node* head, int pos, int val) {
    return addNodeBF(head, pos, val);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head = addNodeBF(head, 2, 3);
    for (Node* cur = head; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";
    return 0;
}

/*
Logic: Traverse to position and adjust pointers to insert new node.  
Time: O(n), Space: O(1)
*/