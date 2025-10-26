#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Brute force: recursive postorder traversal
void postorderBF(Node* root, vector<int>& res) {
    if (!root) return;
    postorderBF(root->left, res);
    postorderBF(root->right, res);
    res.push_back(root->val);
}

// Optimized: iterative postorder using two stacks
vector<int> postorderOpt(Node* root) {
    vector<int> res;
    if (!root) return res;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top(); s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        res.push_back(s2.top()->val);
        s2.pop();
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> res;
    postorderBF(root, res);
    auto it = postorderOpt(root);
    cout << "BF: "; for (int x: res) cout << x << " "; cout << "\n";
    cout << "Opt: "; for (int x: it) cout << x << " "; cout << "\n";
    return 0;
}
