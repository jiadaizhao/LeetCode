class TrieNode {
public:
    TrieNode () {
        next.resize(26);
    }
    
    vector<TrieNode*> next;
    vector<string> prefix;
};


class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> result;
        int m = words.size();
        if (m == 0)
        {
            return result;
        }
        int n = words[0].size();
        
        TrieNode* root = new TrieNode();
        for (string& word : words)
        {
            insert(word, root);
        }
        
        vector<string> path;
        for (int i = 0; i < m; ++i)
        {
            path.push_back(words[i]);
            dfs(root, n, path, result);
            path.pop_back();
        }
        
        return result;
    }
    
private:
    void insert(string word, TrieNode* node)
    {
        for (char c : word)
        {
            int i = c - 'a';
            if (node->next[i] == nullptr)
            {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
            node->prefix.push_back(word);
        }
    }
    
    vector<string> findCandidates(TrieNode* node, string prefix)
    {
        for (char c : prefix)
        {
            int i = c - 'a';
            if (node->next[i] == nullptr)
            {
                return vector<string>();
            }
            node = node->next[i];
        }
        
        return node->prefix;
    }
    
    void dfs(TrieNode* root, int n, vector<string>& path, vector<vector<string>>& result)
    {
        if (path.size() == n)
        {
            result.push_back(path);
            return;
        }
        
        string prefix;
        int index = path.size();
        for (string& p : path)
        {
            prefix += p[index];
        }
        
        vector<string> candidates = findCandidates(root, prefix);
        for (string& candidate : candidates)
        {
            path.push_back(candidate);
            dfs(root, n, path, result);
            path.pop_back();
        }
    }
};
