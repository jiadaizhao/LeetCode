class TrieNode {
public:
    TrieNode* next[26];
    int index;
    TrieNode() {
        memset(next, NULL, sizeof(next));
        index = -1;
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
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode;
        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i], i);
        }
        
        string result = search(root, words);
        delete root;
        return result;
    }
    
private:
    void insert(TrieNode* root, string word, int index) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->next[i] == NULL) {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->index = index;
    }
    
    string search(TrieNode* root, vector<string>& words) {
        stack<TrieNode*> St;
        St.push(root);
        string result;
        while (!St.empty()) {
            TrieNode* node = St.top();
            St.pop();
            if (node->index != -1 || node == root) {
                if (node != root) {
                    string word = words[node->index];
                    if (word.size() > result.size() || (word.size() == result.size() && word < result)) {
                        result = word;
                    }
                }
                
                for (int i = 0; i < 26; ++i) {
                    if (node->next[i]) {
                        St.push(node->next[i]);
                    }                    
                }
            }
        }
        
        return result;
    }
};
