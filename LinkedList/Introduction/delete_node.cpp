#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

Node* delNodeBF(Node* head, int pos) {
    if (!head) return head;
    if (pos == 0) {
        Node* nxt = head->next;
        delete head;
        return nxt;
    }
    Node* cur = head;
    for (int i=0; cur && i < pos-1; i++) cur = cur->next;
    if (!cur || !cur->next) return head;
    Node* toDel = cur->next;
    cur->next = toDel->next;
    delete toDel;
    return head;
}

Node* delNodeOpt(Node* head, int pos) {
    return delNodeBF(head, pos);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = delNodeBF(head, 1);
    for (Node* cur = head; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";
    return 0;
}

/*
Logic: Traverse to previous node and re-link skipping deleted node.  
Time: O(n), Space: O(1)
*/