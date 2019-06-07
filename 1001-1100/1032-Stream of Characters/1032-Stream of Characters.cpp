class TrieNode {
public:
    TrieNode* next[26];
    bool isEnd;
    TrieNode() {
        memset(next, 0, sizeof(next));
        isEnd = false;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        maxLen = 0;
        for (string word : words) {
            TrieNode* node = root;
            maxLen = max(maxLen, (int)(word.size()));
            for (int i = word.size() - 1; i >= 0; --i) {
                int index = word[i] - 'a';
                if (node->next[index] == nullptr) {
                    node->next[index] = new TrieNode();
                }
                node = node->next[index];
            }
            node->isEnd = true;
        }
    }
    
    bool query(char letter) {
        history = (letter + history).substr(0, maxLen);
        TrieNode *node = root;
        for (char c : history) {
            if (node->next[c - 'a'] == nullptr) {
                return false;
            }
            node = node->next[c - 'a'];
            if (node->isEnd) {
                return true;
            }
        }
        return false;
    }
    
private:
    TrieNode *root;
    int maxLen;
    string history;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */


class TrieNode {
public:
    TrieNode* next[26];
    bool isEnd;
    TrieNode* fail;
    TrieNode() {
        memset(next, 0, sizeof(next));
        isEnd = false;
        fail = nullptr;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->next[c - 'a'] == nullptr) {
                    node->next[c - 'a'] = new TrieNode();
                }
                node = node->next[c - 'a'];
            }
            node->isEnd = true;
        }

        queue<TrieNode*> Q;
        for (int i = 0; i < 26; ++i) {
            if (root->next[i]) {
                root->next[i]->fail = root;
                Q.push(root->next[i]);
            }
        }
        while (!Q.empty()) {
            TrieNode* node = Q.front();
            Q.pop();
            for (int i = 0; i < 26; ++i) {
                if (node->next[i]) {
                    Q.push(node->next[i]);
                    node->next[i]->fail = root;
                    TrieNode* failTo = node->fail;
                    while (failTo) {
                        if (failTo->next[i]) {
                            node->next[i]->fail = failTo->next[i];
                            break;
                        }
                        else {
                            failTo = failTo->fail;
                        }
                    }
                }
            }
        }

        curr = root;
    }
    
    bool query(char letter) {
        while (curr && curr->next[letter - 'a'] == nullptr) {
            curr = curr->fail;
        }

        if (curr == nullptr) {
            curr = root;
            return false;
        }
        else {
            curr = curr->next[letter - 'a'];
            if (curr->isEnd) {
                return true;
            }
            TrieNode* node = curr->fail;
            while (node && !(node->isEnd)) {
                node = node->fail;
            }
            return node != nullptr;
        }
    }

private:
    TrieNode *root, *curr;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
