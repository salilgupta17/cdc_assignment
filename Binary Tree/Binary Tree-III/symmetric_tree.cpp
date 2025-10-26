#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Helper function to check mirrors
bool isMirror(Node* t1, Node* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

// Brute force: check symmetric nature recursively
bool isSymmetricBF(Node* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// Optimized: same best approach recursively
bool isSymmetricOpt(Node* root) {
    return isSymmetricBF(root);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    cout << (isSymmetricBF(root) ? "Symmetric" : "Not Symmetric") << "\n";
    return 0;
}
