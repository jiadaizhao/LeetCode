class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> table(words.begin(), words.end());
        for (string word : words) {
            for (int i = 1; i < word.size(); ++i) {
                table.erase(word.substr(i));
            }                
        }
            
        int total = 0;
        for (string word : table) {
            total += word.size() + 1;
        }
        return total;
    }
};

class TrieNode {
public:
    TrieNode* next[26];
    int count;
    TrieNode() {
        memset(next, 0, sizeof(next));
        count = 0;
    }
    ~TrieNode() {
        for (TrieNode* p : next) {
            if (p) {
                delete p;
            }
        }
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode();
        unordered_map<TrieNode*, int> table;
        for (int i = 0; i < words.size(); ++i) {
            TrieNode* node = root;
            for (int j = words[i].size() - 1; j >= 0; --j) {
                int index = words[i][j] - 'a';
                if (node->next[index] == nullptr) {
                    node->next[index] = new TrieNode();
                }
                ++node->count;
                node = node->next[index];
            }
                        
            table[node] = i;
        }

        int total = 0;
        for (auto t : table) {
            if (t.first->count == 0) {
                total += words[t.second].size() + 1;
            }
        }
        delete root;
        return total;
    }
};
