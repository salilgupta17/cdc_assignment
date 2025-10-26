#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Brute force and optimized are same: recursive sum
int sumOfLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;
    return sumOfLeaves(root->left) + sumOfLeaves(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << "Sum of leaves: " << sumOfLeaves(root) << '\n';
    return 0;
}
