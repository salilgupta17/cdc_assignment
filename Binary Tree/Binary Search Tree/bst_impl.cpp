#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Brute force: insert node by traversing the tree (recursive)
Node* insertBF(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val)
        root->left = insertBF(root->left, val);
    else
        root->right = insertBF(root->right, val);
    return root;
}

// Optimized: iterative insertion to avoid recursion overhead
Node* insertOpt(Node* root, int val) {
    Node* newNode = new Node(val);
    if (!root) return newNode;
    Node* cur = root;
    Node* parent = nullptr;
    while (cur) {
        parent = cur;
        if (val < cur->val) cur = cur->left;
        else cur = cur->right;
    }
    if (val < parent->val) parent->left = newNode;
    else parent->right = newNode;
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    vector<int> vals = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int v : vals) root = insertBF(root, v);
    cout << "Inorder (BF insert): "; inorder(root); cout << '\n';

    Node* root2 = nullptr;
    for (int v : vals) root2 = insertOpt(root2, v);
    cout << "Inorder (Opt insert): "; inorder(root2); cout << '\n';
    return 0;
}
