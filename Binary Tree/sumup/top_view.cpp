#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

vector<int> topView(Node* root) {
    vector<int> res;
    if (!root) return res;
    map<int, int> hdNode; // horizontal distance - node val
    queue<pair<Node*, int>> q; // node and HD
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        if (!hdNode.count(hd)) hdNode[hd] = node->val;
        if (node->left) q.push({node->left, hd-1});
        if (node->right) q.push({node->right, hd+1});
    }
    for (auto& p : hdNode) res.push_back(p.second);
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    auto v = topView(root);
    for (int x : v) cout << x << " ";
    cout << '\n';
    return 0;
}
