#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(Node* root) {
    vector<int> res;
    if (!root) return res;
    map<int, int> hdNode;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        hdNode[hd] = node->val;
        if (node->left) q.push({node->left, hd-1});
        if (node->right) q.push({node->right, hd+1});
    }
    for (auto& p : hdNode) res.push_back(p.second);
    return res;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    auto v = bottomView(root);
    for (int x : v) cout << x << " ";
    cout << '\n';
    return 0;
}
