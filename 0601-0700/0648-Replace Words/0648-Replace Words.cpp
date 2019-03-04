class TrieNode {
public:
    TrieNode* next[26];
    string str;
    TrieNode() {
        memset(next, NULL, sizeof(next));
        str = "";
    }
    ~TrieNode() {
        for (auto p : next) {
            if (p) {
                delete p;
            }
        }
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* root = new TrieNode();
        for (string word : dict) {
            insert(root, word);
        }
        
        int n = sentence.size();
        int i = 0;        
        string result;
        while (i < n) {
            string word;
            while (i < n && sentence[i] != ' ') {
                word += sentence[i++];
            }
            
            result += findRoot(root, word);
            if (i < n) {
                result += ' ';
            }            
            ++i;
        }
        
        delete root;
        return result;        
    }

private:
    void insert(TrieNode* root, string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->str = word;
    }
    
    string findRoot(TrieNode* root, string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->next[c - 'a'] == nullptr) {
                return word;
            }
            node = node->next[c - 'a'];
            if (node->str.size()) {
                return node->str;
            }
        }
        
        return word;
    }
};
