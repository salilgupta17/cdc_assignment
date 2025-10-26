#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// BFS traversal using queue
vector<vector<int>> levelOrderBF(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = (int)q.size();
        vector<int> level;
        for (int i=0; i<size; i++) {
            Node* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    auto levels = levelOrderBF(root);
    for (auto &lvl : levels) {
        for (int x : lvl) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
