struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    int wordCount;
    TrieNode() : isEndOfWord(false), wordCount(0) {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* curr = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!curr->children[idx])
            curr->children[idx] = new TrieNode();
        curr = curr->children[idx];
    }
    curr->isEndOfWord = true;
    curr->wordCount += 1;
}

int countWord(TrieNode* root, string word) {
    TrieNode* curr = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!curr->children[idx]) return 0;
        curr = curr->children[idx];
    }
    return curr->isEndOfWord ? curr->wordCount : 0;
}

/*
Count how many times a specific word occurs (if duplicates are inserted) or total words stored.

Enhanced TrieNode Structure:
- Added 'wordCount' field to track frequency of each word
- Incremented each time the same word is inserted
- Allows tracking duplicate insertions

Usage:
- Insert the same word multiple times
- Query how many times a specific word was inserted
- Useful for frequency analysis, word counting applications

Time Complexity:
- Insert: O(L) where L is word length
- Count: O(L) where L is word length
*/