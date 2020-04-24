class TrieNode {
public:
    TrieNode* next[26];
    vector<string> prefix;
    TrieNode() {
        memset(next, NULL, sizeof(next));
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
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode* root = new TrieNode();
        int n = words[0].size();
        for (string word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->next[index] == nullptr) {
                    node->next[index] = new TrieNode();
                }
                node = node->next[index];
                node->prefix.push_back(word);
            }
        }
        
        vector<vector<string>> result;
        vector<string> path;
        for (string word : words) {
            path.push_back(word);
            dfs(root, path, result);
            path.pop_back();
        }
        
        delete root;
        return result;
    }
    
private:
    void dfs(TrieNode* root, vector<string>& path, vector<vector<string>>& result) {
        if (path.size() == path[0].size()) {
            result.push_back(path);
            return;
        }
        string s;
        for (int i = 0; i < path.size(); ++i) {
            s += path[i][path.size()];
        }
        vector<string> candidates = search(root, s);
        for (string str : candidates) {
            path.push_back(str);
            dfs(root, path, result);
            path.pop_back();
        }
    }
    
    vector<string> search(TrieNode* root, string s) {
        TrieNode* node = root;
        for (char c : s) {
            int index = c - 'a';
            if (node->next[index] == nullptr) {
                return {};
            }
            node = node->next[index];
        }
        return node->prefix;
    }
};
