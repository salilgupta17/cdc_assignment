#include <bits/stdc++.h>
using namespace std;

// BF not practical, as manual parsing needed and slow

int evalPostfixOpt(const string &exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch(c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

int main() {
    string exp = "231*+9-"; // example from standard postfix examples
    cout << "Eval postfix: " << evalPostfixOpt(exp) << "\n";
    return 0;
}

/*
Logic: Use stack to evaluate postfix by pushing operands and applying operators.  
Time: O(n), Space: O(n)
*/