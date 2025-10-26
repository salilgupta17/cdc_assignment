#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
class MyHashMap {
private:
    static const int SIZE = 1000;
    list<pair<K, V>> table[SIZE];

    int hashFunc(K key) {
        return hash<K>{}(key) % SIZE;
    }

public:
    // Put key-value pair into map (replace if key exists)
    void put(K key, V value) {
        int idx = hashFunc(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    // Get value associated with key, or nullptr if not found
    V* get(K key) {
        int idx = hashFunc(key);
        for (auto& p : table[idx]) {
            if (p.first == key) return &p.second;
        }
        return nullptr;
    }

    // Check if key exists in map
    bool containsKey(K key) {
        int idx = hashFunc(key);
        for (auto& p : table[idx]) {
            if (p.first == key) return true;
        }
        return false;
    }

    // Return all keys as vector
    vector<K> keySet() {
        vector<K> keys;
        for (int i = 0; i < SIZE; i++) {
            for (auto& p : table[i]) {
                keys.push_back(p.first);
            }
        }
        return keys;
    }
};

int main() {
    MyHashMap<string,int> map;
    map.put("one", 1);
    map.put("two", 2);
    map.put("three", 3);
    if (map.containsKey("two")) cout << "two -> " << *map.get("two") << "\n";
    map.put("two", 22);
    cout << "two -> " << *map.get("two") << "\n";
    auto keys = map.keySet();
    cout << "Keys: ";
    for (auto &k: keys) cout << k << " ";
    cout << '\n';
    return 0;
}
