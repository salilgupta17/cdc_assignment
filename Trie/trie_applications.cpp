/*
===== Application of Trie =====

1. Autocomplete and Predictive Text
   - Suggests words based on prefix input
   - Used in search engines, text editors, IDEs
   - Efficiently retrieves all words with a given prefix

2. Spell Checking
   - Verifies if a word exists in dictionary
   - Suggests corrections by finding similar words
   - Fast lookup for validity checking

3. IP Routing (Longest Prefix Matching)
   - Routes network packets based on IP address prefixes
   - Finds the longest matching prefix for routing decisions
   - Critical in networking infrastructure

4. Dictionary/Word Storage
   - Efficient storage and retrieval of words
   - O(L) insertion, search, and deletion (L = word length)
   - Memory efficient for large dictionaries with common prefixes

5. Word Break Problem
   - Segments strings into valid dictionary words
   - Dynamic programming combined with Trie lookup
   - Used in natural language processing

6. Pattern Searching (Aho-Corasick Algorithm)
   - Scans multiple patterns efficiently in a text
   - Used in string matching, virus detection, DNA analysis
   - Multi-pattern matching in O(n + m + z) time
     where n = text length, m = total pattern length, z = matches

7. Phone Directory
   - Autocomplete names based on number/letter input
   - Quick prefix-based search in contact lists

8. Browser History and URL Management
   - Store and search browsing history
   - Autocomplete URLs based on user input

Key Advantages:
- Prefix-based operations are very efficient
- Lexicographical ordering comes naturally
- Space efficient when many strings share common prefixes
- No hash collisions unlike hash tables
*/