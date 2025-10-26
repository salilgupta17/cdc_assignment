#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Brute force: inorder traversal then check sorted
void inorderBF(Node* root, vector<int>& res) {
    if (!root) return;
    inorderBF(root->left, res);
    res.push_back(root->val);
    inorderBF(root->right, res);
}

bool isValidBSTBF(Node* root) {
    vector<int> vals;
    inorderBF(root, vals);
    for (int i = 1; i < (int)vals.size(); i++) {
        if (vals[i] <= vals[i - 1]) return false;
    }
    return true;
}

// Optimized: use min/max range checks during traversal
bool isValidBSTOpt(Node* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTOpt(root->left, minVal, root->val) &&
           isValidBSTOpt(root->right, root->val, maxVal);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << (isValidBSTBF(root) ? "Valid BF" : "Invalid BF") << '\n';
    cout << (isValidBSTOpt(root) ? "Valid Opt" : "Invalid Opt") << '\n';
    return 0;
}
