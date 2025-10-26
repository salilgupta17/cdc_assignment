#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Brute force: recursive inorder traversal
void inorderBF(Node* root, vector<int>& res) {
    if (!root) return;
    inorderBF(root->left, res);
    res.push_back(root->val);
    inorderBF(root->right, res);
}

// Optimized: iterative inorder traversal using stack
vector<int> inorderOpt(Node* root) {
    vector<int> res;
    stack<Node*> st;
    Node* curr = root;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> res;
    inorderBF(root, res);
    auto it = inorderOpt(root);
    cout << "BF: "; for (int x: res) cout << x << " "; cout << "\n";
    cout << "Opt: "; for (int x: it) cout << x << " "; cout << "\n";
    return 0;
}
