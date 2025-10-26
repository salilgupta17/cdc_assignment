#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Brute force: calculate height for each node and diameter
int heightBF(Node* root) {
    if (!root) return 0;
    return 1 + max(heightBF(root->left), heightBF(root->right));
}

int diameterBF(Node* root) {
    if (!root) return 0;
    int lheight = heightBF(root->left);
    int rheight = heightBF(root->right);
    int ldiameter = diameterBF(root->left);
    int rdiameter = diameterBF(root->right);
    return max(lheight + rheight, max(ldiameter, rdiameter));
}

// Optimized: single traversal to compute height and update diameter
int diameterOptHelper(Node* root, int& diameter) {
    if (!root) return 0;
    int lheight = diameterOptHelper(root->left, diameter);
    int rheight = diameterOptHelper(root->right, diameter);
    diameter = max(diameter, lheight + rheight);
    return 1 + max(lheight, rheight);
}

int diameterOpt(Node* root) {
    int diameter = 0;
    diameterOptHelper(root, diameter);
    return diameter;
}

/*
Logic: BF recalculates height multiple times, O(n^2).  
Opt computes diameter and height in one traversal, O(n).
*/

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Diameter BF: " << diameterBF(root) << "\n";
    cout << "Diameter Opt: " << diameterOpt(root) << "\n";
    return 0;
}
