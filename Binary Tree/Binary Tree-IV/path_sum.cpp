#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Brute force: recursive check of all paths from root to leaves
bool hasPathSumBF(Node* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return (targetSum == root->val);
    return hasPathSumBF(root->left, targetSum - root->val) ||
           hasPathSumBF(root->right, targetSum - root->val);
}

// Optimized: same recursion is optimal for this problem
bool hasPathSumOpt(Node* root, int targetSum) {
    return hasPathSumBF(root, targetSum);
}

/*
Logic: Check if root-to-leaf path sums to target. Recursive solution O(n).
*/

int main() {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    int target = 22;
    cout << (hasPathSumBF(root, target) ? "Path exists" : "No path") << "\n";
    return 0;
}
