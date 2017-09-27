class TrieNode {
public:
    vector<TrieNode*> next;
    bool isEnd;
    string str;
    TrieNode() {
        next.resize(26);
        isEnd = false;
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
        for (string word : dict)
        {
            insert(root, word);
        }
        
        int n = sentence.size();
        int i = 0;
        string word;
        string result;
        while (i < n)
        {
            while (i < n && sentence[i] != ' ')
            {
                word += sentence[i++];
            }
            
            result += findRoot(root, word);
            if (i < n)
            {
                result += ' ';
            }            
            word = "";
            ++i;
        }
        
        delete root;
        return result;        
    }

private:
    void insert(TrieNode* root, string word)
    {
        TrieNode* node = root;
        for (char c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
        node->str = word;
    }
    
    string findRoot(TrieNode* root, string word)
    {
        TrieNode* node = root;
        for (char c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                return word;
            }
            node = node->next[c - 'a'];
            if (node->isEnd)
            {
                return node->str;
            }
        }
        
        return word;
    }
};
