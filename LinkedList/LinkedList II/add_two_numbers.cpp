#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

// Brute force: extract numbers, sum, rebuild list
Node* addTwoBF(Node* l1, Node* l2) {
    long long num1=0, num2=0, base=1;
    while (l1) { num1 += l1->val * base; l1=l1->next; base*=10; }
    base=1;
    while (l2) { num2 += l2->val * base; l2=l2->next; base*=10; }
    long long sum = num1 + num2;
    if (sum == 0) return new Node(0);
    Node* head = nullptr;
    while (sum) {
        Node* n = new Node(sum%10);
        n->next = head;
        head = n;
        sum /= 10;
    }
    // reverse the list to restore order
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// Optimized: digit-wise addition with carry
Node* addTwoOpt(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* cur = dummy;
    int carry=0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum/10;
        cur->next = new Node(sum%10);
        cur = cur->next;
    }
    return dummy->next;
}

int main() {
    Node* a = new Node(2); a->next = new Node(4); a->next->next = new Node(3);
    Node* b = new Node(5); b->next = new Node(6); b->next->next = new Node(4);
    Node* sum = addTwoOpt(a,b);
    for (Node* cur = sum; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF converts lists to integers and sums then back;  
Opt adds per digit with carry in one pass.  
Time: O(max(m,n)), Space: BF,O(m+n), Opt O(m+n)
*/