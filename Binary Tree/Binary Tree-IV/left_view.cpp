#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Brute force: use level order traversal to print first element per level
vector<int> leftViewBF(Node* root) {
    vector<int> view;
    if (!root) return view;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* temp = q.front(); q.pop();
            if (i == 0) view.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return view;
}

// Optimized: recursive DFS for left view
void leftViewDFS(Node* root, int level, vector<int>& view) {
    if (!root) return;
    if (level == (int)view.size()) view.push_back(root->val);
    leftViewDFS(root->left, level + 1, view);
    leftViewDFS(root->right, level + 1, view);
}

vector<int> leftViewOpt(Node* root) {
    vector<int> view;
    leftViewDFS(root, 0, view);
    return view;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    auto bf = leftViewBF(root);
    auto opt = leftViewOpt(root);
    cout << "Left View BF: ";
    for (int v: bf) cout << v << " ";
    cout << "\nLeft View Opt: ";
    for (int v: opt) cout << v << " ";
    cout << '\n';
    return 0;
}
