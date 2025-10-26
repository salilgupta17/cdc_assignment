#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Brute force: recursively check nodes individually
bool isSameTreeBF(Node* p, Node* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (p->val == q->val) && isSameTreeBF(p->left, q->left) && isSameTreeBF(p->right, q->right);
}

// Optimized: same recursive approach (best approach)
bool isSameTreeOpt(Node* p, Node* q) {
    return isSameTreeBF(p, q);
}

int main() {
    Node* a = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    Node* b = new Node(1);
    b->left = new Node(2);
    b->right = new Node(3);
    cout << (isSameTreeBF(a, b) ? "Same" : "Different") << "\n";
    return 0;
}
