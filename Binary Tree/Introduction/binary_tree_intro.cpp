#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Basic insertion example (binary tree, not BST)
Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        if (!node->left) {
            node->left = new Node(val);
            break;
        } else q.push(node->left);
        if (!node->right) {
            node->right = new Node(val);
            break;
        } else q.push(node->right);
    }
    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root = insertNode(root, 4);
    // Tree structure
    return 0;
}

/*
Logic: Binary tree nodes have left and right child pointers.  
Basic example shows level order insertion in a binary tree.  
*/