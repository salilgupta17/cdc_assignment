#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

// Brute force: push into stack and rebuild list
Node* revListBF(Node* head) {
    stack<int> st;
    Node* cur = head;
    while (cur) {
        st.push(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        cur->val = st.top();
        st.pop();
        cur = cur->next;
    }
    return head;
}

// Optimized: reverse pointers in one pass
Node* revListOpt(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = revListOpt(head);
    for (Node* cur = head; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF saves values on stack and rewrites;  
Opt reverses links in-place with O(1) space.  
Time: O(n), Space: BF O(n), Opt O(1)
*/