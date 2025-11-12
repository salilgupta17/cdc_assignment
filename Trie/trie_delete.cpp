const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
};

bool isEmpty(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i]) return false;
    return true;
}

TrieNode* deleteKey(TrieNode* node, const string& key, int depth = 0) {
    if (!node) return nullptr;
    if (depth == key.size()) {
        if (node->isEndOfWord) node->isEndOfWord = false;
        if (isEmpty(node)) {
            delete node;
            return nullptr;
        }
        return node;
    }
    int idx = key[depth] - 'a';
    node->children[idx] = deleteKey(node->children[idx], key, depth + 1);
    if (isEmpty(node) && !node->isEndOfWord) {
        delete node;
        return nullptr;
    }
    return node;
}

/*
Deleting a word from a Trie involves:
1. Unmarking the leaf node if the word is a prefix of another word.
2. Removing nodes only if they are not part of any other word (i.e., no children and not isEndOfWord).
3. Recursively traversing and cleaning up nodes bottom-up, only deleting where safe.

The deletion process ensures that:
- If the word exists as a prefix of other words, only the isEndOfWord flag is unset
- Empty nodes with no children are deleted to free memory
- Nodes that are part of other words are preserved
*/