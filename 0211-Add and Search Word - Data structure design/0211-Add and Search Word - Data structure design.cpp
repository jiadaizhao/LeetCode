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
    
    TrieNode* next[26];
    bool isEnd;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->next[i] == nullptr) {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }

private:
    TrieNode* root;
    bool search(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; ++j) {
                    node = tmp->next[j];
                    if (node != nullptr && search(word.substr(i + 1), node)) {
                        return true;
                    }
                }
                
                return false;
            }
            else {
                int index = word[i] - 'a';
                if (node->next[index] == nullptr) {
                    return false;
                }
                node = node->next[index];
            }
        }
        
        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
 