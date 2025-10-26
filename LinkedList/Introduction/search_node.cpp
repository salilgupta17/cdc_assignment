#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

int searchBF(Node* head, int key) {
    int pos = 0;
    for (Node* cur = head; cur; cur = cur->next, pos++)
        if (cur->val == key) return pos;
    return -1;
}

int searchOpt(Node* head, int key) {
    return searchBF(head, key);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    cout << searchBF(head, 2) << "\n";
    return 0;
}

/*
Logic: Linear scan to find position of key.  
Time: O(n), Space: O(1)
*/