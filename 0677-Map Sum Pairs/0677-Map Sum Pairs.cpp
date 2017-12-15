class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
    int sum;
    TrieNode() {
        sum = 0;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int orig = 0;
        if (table.find(key) != table.end()) {
            orig = table[key];
        }
        table[key] = val;
        int diff = val - orig;
        if (diff == 0) {
            return;
        }
        
        TrieNode* node = root;
        for (char c : key) {
            if (node->next.find(c) == node->next.end()) {
                node->next[c] = new TrieNode();
            }
            node = node->next[c];
            node->sum += diff;
        }
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->next.find(c) == node->next.end()) {
                return 0;
            }
            node = node->next[c];
        }
        return node->sum;
    }
    
    ~MapSum() {
        delete root;
    }
    
private:
    unordered_map<string, int> table;
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
