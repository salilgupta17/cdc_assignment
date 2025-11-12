struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left, *right;
    HuffmanNode(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct cmp { // Min-heap comparator
    bool operator()(HuffmanNode* a, HuffmanNode* b) { return a->freq > b->freq; }
};

void buildHuffman(const vector<pair<char, int>>& freqData) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp> pq;
    for (auto& p : freqData)
        pq.push(new HuffmanNode(p.first, p.second));
    while (pq.size() > 1) {
        auto l = pq.top(); pq.pop();
        auto r = pq.top(); pq.pop();
        HuffmanNode* parent = new HuffmanNode('\0', l->freq + r->freq);
        parent->left = l; parent->right = r;
        pq.push(parent);
    }
}

/*
===== Huffman Coding Algorithm =====

Huffman Coding is a lossless data compression algorithm that assigns variable-length 
codes to characters based on their frequency. More frequent characters get shorter codes.

Algorithm Steps:
1. Build a min-heap of nodes with frequencies.
2. Combine two smallest frequency nodes into a new node.
3. Repeat until one root remains.
4. Traverse the tree to assign binary codes to characters (left = 0, right = 1).

How it Works:
- Characters with higher frequency get shorter bit sequences
- Characters with lower frequency get longer bit sequences
- No code is a prefix of another (prefix-free property)
- Optimal prefix code for given character frequencies

Example:
Input: {('a', 5), ('b', 9), ('c', 12), ('d', 13), ('e', 16), ('f', 45)}
Frequency distribution determines the tree structure

Process:
1. Create leaf nodes for each character with its frequency
2. Build min-heap
3. Extract two minimum frequency nodes
4. Create internal node with frequency = sum of two nodes
5. Make the two nodes children of the internal node
6. Insert internal node back to heap
7. Repeat until heap has only one node (root)

Code Assignment:
- Traverse tree from root to each leaf
- Append '0' for left edge, '1' for right edge
- Result: Variable-length prefix-free codes

Time Complexity: O(n log n) where n is the number of unique characters
Space Complexity: O(n) for the heap and tree

Applications:
- File compression (ZIP, GZIP)
- Image compression (JPEG uses Huffman-like coding)
- Data transmission (reduce bandwidth)
- Network protocols
- Multimedia codecs

Advantages:
- Optimal prefix code
- Simple to implement
- Efficient compression for known frequency distribution
- Lossless compression

Disadvantages:
- Requires two passes (frequency analysis + encoding)
- Not adaptive to changing data patterns
- Less effective when character frequencies are uniform
*/