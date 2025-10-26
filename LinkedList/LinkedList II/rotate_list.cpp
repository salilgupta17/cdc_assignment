#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

Node* rotateBF(Node* head, int k) {
    if (!head) return head;
    vector<int> vals;
    Node* cur = head;
    while (cur) {
        vals.push_back(cur->val);
        cur = cur->next;
    }
    int n = vals.size();
    k = k % n;
    rotate(vals.rbegin(), vals.rbegin()+k, vals.rend());
    cur = head;
    int idx = 0;
    while (cur) {
        cur->val = vals[idx++];
        cur = cur->next;
    }
    return head;
}

Node* rotateOpt(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    Node* cur = head;
    int n = 1;
    while (cur->next) {
        cur = cur->next;
        n++;
    }
    cur->next = head; // make circular
    k = k % n;
    int steps = n - k;
    cur = head;
    for(int i=1; i<steps; i++) cur = cur->next;
    head = cur->next;
    cur->next = nullptr;
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = rotateOpt(head, 1);
    for (Node* cur = head; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF rotates by rearranging data;  
Opt uses circular linkage and cutting.  
Time: O(n), Space: BF O(n), Opt O(1)
*/