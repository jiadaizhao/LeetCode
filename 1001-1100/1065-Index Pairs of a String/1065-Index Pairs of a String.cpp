class TrieNode {
public:
    TrieNode() {
        memset(next, NULL, sizeof(next));
        isEnd = false;
    }
    
    ~TrieNode() {
        for (TrieNode* p : next) {
            if (p) {
                delete p;
            }
        }
    }
    TrieNode *next[26];
    bool isEnd;
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->next[c - 'a'] == nullptr) {
                    curr->next[c - 'a'] = new TrieNode();
                }
                curr = curr->next[c - 'a'];
            }
            curr->isEnd = true;
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < text.size(); ++i) {
            int j = i;
            TrieNode* curr = root;
            while (j < text.size() && curr->next[text[j] - 'a']) {
                curr = curr->next[text[j] - 'a'];
                if (curr->isEnd) {
                    result.push_back({i, j});
                }
                ++j;
            }
        }
        
        delete root;
        return result;
    }
};
