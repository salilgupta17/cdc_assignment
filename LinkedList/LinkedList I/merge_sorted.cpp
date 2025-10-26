#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

Node* mergeBF(Node* l1, Node* l2) {
    vector<int> vals;
    while (l1) { vals.push_back(l1->val); l1=l1->next; }
    while (l2) { vals.push_back(l2->val); l2=l2->next; }
    sort(vals.begin(), vals.end());
    Node* dummy = new Node(0);
    Node* cur = dummy;
    for (int v : vals) {
        cur->next = new Node(v);
        cur = cur->next;
    }
    return dummy->next;
}

Node* mergeOpt(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeOpt(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeOpt(l1, l2->next);
        return l2;
    }
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(3);
    Node* b = new Node(2);
    b->next = new Node(4);
    Node* merged = mergeOpt(a, b);
    for (Node* cur = merged; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF copy all values and sort;  
Opt merges recursively in O(n+m).  
Time: O(n+m), Space: BF O(n+m), Opt O(n+m) recursion stack.
*/