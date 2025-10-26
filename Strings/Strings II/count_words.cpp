#include <bits/stdc++.h>
using namespace std;

// Brute force: split string by spaces, count tokens
int countWordsBF(string s) {
    int count = 0;
    string word = "";
    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) count++;
            word = "";
        } else {
            word += c;
        }
    }
    if (!word.empty()) count++;
    return count;
}

// Optimized: use stringstream to split
int countWordsOpt(string s) {
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word) count++;
    return count;
}

int main() {
    string s = "  Hello   world  this is   a test \n";
    cout << "BF: " << countWordsBF(s) << "\n";
    cout << "Opt: " << countWordsOpt(s) << "\n";
    return 0;
}

/*
Logic: BF manually tokenizes by spaces, Opt uses stringstream.  
Time: O(n), Space: O(n) for stream.
*/