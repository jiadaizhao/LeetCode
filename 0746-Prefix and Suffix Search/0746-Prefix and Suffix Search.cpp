class WordFilter {
public:
    WordFilter(vector<string> words) {
        rootP = new TrieNode();
        rootS = new TrieNode();
        int n =  words.size();
        for (int i = n - 1; i >= 0; --i) {
            string s = words[i];
            insert(rootP, s, i);
            reverse(s.begin(), s.end());
            insert(rootS, s, i);
        }
    }    
    
    ~WordFilter() {
        delete rootP;
        delete rootS;
    }
    
    int f(string prefix, string suffix) {
        vector<int> p = search(rootP, prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> s = search(rootS, suffix);
        return maxWeight(p, s);
    }
    
private:
    class TrieNode {
    public:
        TrieNode* next[26];
        vector<int> weights;
        TrieNode() {
            memset(next, NULL, sizeof(next));
        }
        
        ~TrieNode() {
            for (auto p : next) {
                if (p) {
                    delete p;
                }
            }
        }
    };
    
    TrieNode *rootP, *rootS;
    
    void insert(TrieNode* root, string word, int weight) {
        TrieNode* node = root;
        node->weights.push_back(weight);
        for (char c : word) {
            int index = c - 'a';
            if (node->next[index] == nullptr) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
            node->weights.push_back(weight);
        }
    }
    
    vector<int> search(TrieNode* root, string prefix) {        
        if (prefix == "") {
            return root->weights;
        }
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->next[index] == nullptr) {
                return {};
            }
            node = node->next[index];
        }
        
        return node->weights;
    }
    
    int maxWeight(vector<int>& p, vector<int>& s) {
        int p1 = 0, p2 = 0;
        while (p1 < p.size() && p2 < s.size()) {
            if (p[p1] < s[p2]) {
                ++p2;
            }
            else if (p[p1] > s[p2]) {
                ++p1;
            }
            else {
                return p[p1];                
            }
        }
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

class WordFilter {
public:
    WordFilter(vector<string> words) {
        root = new TrieNode();
        for (int w = 0; w < words.size(); ++w) {
            string word = words[w];
            word += '{';
            for (int i = 0; i < word.size(); ++i) {
                TrieNode* node = root;
                for (int j = i; j < word.size() * 2 - 1; ++j) {
                    int index = word[j % word.size()] - 'a';
                    if (node->next[index] == nullptr) {
                        node->next[index] = new TrieNode();
                    }
                    node = node->next[index];
                    node->weight = w;
                }
            }
        }
    }    
    
    ~WordFilter() {
        delete root;
    }
    
    int f(string prefix, string suffix) {
        string s = suffix + '{' + prefix;
        TrieNode* node = root;
        for (char c : s) {
            int index = c - 'a';
            if (node->next[index] == nullptr) {
                return -1;
            }
            node = node->next[index];
        }
        return node->weight;
    }
    
private:
    class TrieNode {
    public:
        TrieNode* next[27];
        int weight;
        TrieNode() {
            memset(next, NULL, sizeof(next));
            weight = 0;
        }
        
        ~TrieNode() {
            for (auto p : next) {
                if (p) {
                    delete p;
                }
            }
        }
    };
    TrieNode* root;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
