class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEndOfWord;
    }
};

/*
- Insert: Traverse down the trie creating nodes for each new character, O(L) time.
- Search: Traverse down for each character, return true if isEndOfWord is set at last node, O(L) time.

===== What is Trie DS? =====
A trie, also called a prefix tree or digital tree, is a rooted tree where:
- Each node corresponds to a character (or element) of a key.
- Paths from root to leaf nodes represent complete keys (e.g., words).
- Each node typically has an array or map linking it to its possible next characters (children).
- The root node is usually empty and every path down the tree represents a possible prefix.

===== Use of Trie =====
- Autocomplete: Efficiently lists words with a given prefix.
- Spell Checking: Quickly searches for valid words or prefixes.
- Longest Prefix Matching: Used widely in IP routing and DNA sequence queries.
- Dictionary Storage and Retrieval: Insert, search, and delete words in O(L) time, where L is the length of the word.
- Prefix Queries: Find all keys with a given prefix in sorted order.

===== Hashmap vs Trie =====
Feature          | Trie                        | Hash Map
-----------------|-----------------------------|----------------------------------
Data Structure   | Tree (prefix-oriented)      | Key-value store
Lookup Time      | O(L) (length of word)       | O(1) average (O(L) worst for string keys)
Prefix Search    | Efficient                   | Not supported
Space Usage      | Can be large for many keys  | More compact for sparse sets
Sorted Iterate   | Can retrieve lex sorted     | Not inherently possible
Hash Collisions  | Not possible                | Possible, needs hash function
Use Cases        | Autocomplete, dictionary    | Direct key-value access

Tries are better than hashmaps for prefix searches, autocomplete, and lexicographical ordering. 
Hashmaps are often more space efficient but not suitable for prefix queries.

===== Trie Node Representation =====
- Each node has pointers to children (TrieNode* children for lowercase English alphabet).
- Each node has a boolean flag (isEndOfWord or isLeaf) to mark end of a word.
*/