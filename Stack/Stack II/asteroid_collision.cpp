#include <bits/stdc++.h>
using namespace std;

// Brute force: simulate collisions by checking all pairs repeatedly
vector<int> asteroidCollBF(vector<int> ast) {
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < (int)ast.size() - 1; i++) {
            if (ast[i] > 0 && ast[i + 1] < 0) {
                int left = ast[i], right = -ast[i + 1];
                if (left == right) {
                    ast.erase(ast.begin() + i, ast.begin() + i + 2);
                    changed = true;
                } else if (left > right) {
                    ast.erase(ast.begin() + i + 1);
                    changed = true;
                } else {
                    ast.erase(ast.begin() + i);
                    changed = true;
                }
                break;
            }
        }
    } while (changed);
    return ast;
}

// Optimized: use stack to simulate collisions efficiently
vector<int> asteroidCollOpt(const vector<int>& ast) {
    stack<int> st;
    for (int a : ast) {
        bool alive = true;
        while (alive && a < 0 && !st.empty() && st.top() > 0) {
            if (st.top() < -a) st.pop();
            else if (st.top() == -a) { st.pop(); alive = false; }
            else alive = false;
        }
        if (alive) st.push(a);
    }
    vector<int> res(st.size());
    for (int i = (int)st.size() - 1; i >= 0; --i) {
        res[i] = st.top(); st.pop();
    }
    return res;
}

int main() {
    vector<int> a = {5, 10, -5};
    auto res = asteroidCollOpt(a);
    cout << "Result: "; for (int x: res) cout << x << " "; cout << "\n";
    return 0;
}

/*
Logic: BF repeatedly simulates collisions, O(n^2).  
Opt uses stack for linear pass simulation, O(n).  
Space: O(n)
*/