#include <bits/stdc++.h>
using namespace std;

bool validParenBF(const string& s) {
    stack<char> st;
    for (char c : s) st.push(c);
    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return s == rev;
}

bool validParenOpt(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string s1 = "()[]{}";
    string s2 = "([)]";
    cout << "BF(s1): " << (validParenBF(s1) ? "true" : "false") << "\n";
    cout << "Opt(s1): " << (validParenOpt(s1) ? "true" : "false") << "\n";
    cout << "BF(s2): " << (validParenBF(s2) ? "true" : "false") << "\n";
    cout << "Opt(s2): " << (validParenOpt(s2) ? "true" : "false") << "\n";
    return 0;
}

/*
Logic: BF reverses string and compares, incorrect for parentheses.  
Opt uses stack to check matching pairs, O(n).  
*/