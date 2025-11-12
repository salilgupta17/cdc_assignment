bool wordBreak(const string& s, TrieNode* root) {
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        TrieNode* curr = root;
        for (int j = i - 1; j >= 0; j--) {
            int idx = s[j] - 'a';
            if (!curr->children[idx]) break;
            curr = curr->children[idx];
            if (curr->isEndOfWord && dp[j])
                dp[i] = true;
        }
    }
    return dp[n];
}

/*
===== Word Break Problem =====

Problem Statement:
Given a string and a dictionary of words, check if the string can be segmented 
into space-separated dictionary words.

Example:
Input: s = "leetcode", dictionary = ["leet", "code"]
Output: true (can be segmented as "leet code")

Input: s = "applepenapple", dictionary = ["apple", "pen"]
Output: true (can be segmented as "apple pen apple")

Input: s = "catsandog", dictionary = ["cats", "dog", "sand", "and", "cat"]
Output: false

Algorithm Approach:
1. Build a Trie from the dictionary words
2. Use dynamic programming where dp[i] indicates if s[0...i-1] can be segmented
3. For each position i, look backwards trying to match dictionary words using Trie
4. If s[j...i-1] is a valid word (found in Trie) and dp[j] is true, then dp[i] = true

Why Combine Trie + DP?
- Trie allows efficient prefix matching while scanning backwards
- DP avoids recomputing the same subproblems
- Early termination when no matching prefix exists in Trie

Time Complexity: O(n²) where n is the length of string s
Space Complexity: O(n) for DP array + O(m*k) for Trie (m = number of words, k = avg word length)

Applications:
- Natural Language Processing
- Text segmentation
- Tokenization in compilers
- URL parsing and validation
*/