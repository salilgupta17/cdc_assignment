#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Brute force: recursive height calculation
int heightBF(Node* root) {
    if (!root) return 0;
    return 1 + max(heightBF(root->left), heightBF(root->right));
}

// Optimized: iterative height using level order traversal (BFS)
int heightOpt(Node* root) {
    if (!root) return 0;
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        height++;
    }
    return height;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << "BF height: " << heightBF(root) << "\n";
    cout << "Opt height: " << heightOpt(root) << "\n";
    return 0;
}
