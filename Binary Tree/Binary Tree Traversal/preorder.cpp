#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Brute force: recursive preorder traversal
void preorderBF(Node* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorderBF(root->left, res);
    preorderBF(root->right, res);
}

// Optimized: iterative preorder using stack
vector<int> preorderOpt(Node* root) {
    vector<int> res;
    if (!root) return res;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* node = st.top(); st.pop();
        res.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> res;
    preorderBF(root, res);
    auto it = preorderOpt(root);
    cout << "BF: "; for (int x: res) cout << x << " "; cout << "\n";
    cout << "Opt: "; for (int x: it) cout << x << " "; cout << "\n";
    return 0;
}
