#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

int countBF(Node* head) {
    int cnt = 0;
    for (Node* cur = head; cur; cur = cur->next) cnt++;
    return cnt;
}

int countOpt(Node* head) {
    return countBF(head);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    cout << countBF(head) << "\n";
    return 0;
}

/*
Logic: Count by traversal.  
Time: O(n), Space: O(1)
*/