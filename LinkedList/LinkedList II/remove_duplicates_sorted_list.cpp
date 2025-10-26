#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

Node* removeDupBF(Node* head) {
    if (!head) return head;
    vector<int> vals;
    Node* cur = head;
    while (cur) {
        if (vals.empty() || vals.back() != cur->val) vals.push_back(cur->val);
        cur = cur->next;
    }
    Node* dummy = new Node(0);
    Node* tail = dummy;
    for (int v : vals) {
        tail->next = new Node(v);
        tail = tail->next;
    }
    return dummy->next;
}

Node* removeDupOpt(Node* head) {
    if (!head) return head;
    Node* cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head = removeDupOpt(head);
    for (Node* cur = head; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";
    return 0;
}
