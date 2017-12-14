struct Node {
    int times;
    string sentence;
    Node(int t, string s): times(t), sentence(s) {}
    bool operator < (Node node) const {
        if (times == node.times) {
            return sentence < node.sentence;
        }
        return times > node.times;
    }
};

struct TrieNode {
    TrieNode() {
        memset(next, NULL, sizeof(next));
        times = 0;
    }
    TrieNode* next[27];
    int times;
    ~TrieNode() {
        for (auto p : next) {
            if (p) {
                delete p;
            }
        }
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        currNode = root;
        curr = "";
        for (int i = 0; i < sentences.size(); ++i) {
            insert(root, sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(root, curr, 1);
            curr = "";
            currNode = root;
            return {};
        }
        else {
            curr += c;
            int index = (c == ' ') ? 26 : c - 'a';
            if (currNode == nullptr || currNode->next[index] == nullptr) {
                currNode = nullptr;
                return {};
            }
            currNode = currNode->next[index];
            vector<Node> candidates;
            dfs(currNode, curr, candidates);
            priority_queue<Node> pq;
            for (auto& node : candidates) {
                pq.push(node);
                if (pq.size() > 3) {
                    pq.pop();
                }
            }
            
            vector<string> result;
            while (!pq.empty()) {
                result.push_back(pq.top().sentence);
                pq.pop();
            }
            
            reverse(result.begin(), result.end());
            return result;
        }
    }
    
    ~AutocompleteSystem() {
        delete root;
    }

private:
    TrieNode* root;
    string curr;
    TrieNode* currNode;
    void insert(TrieNode* root, string sentence, int times) {
        TrieNode* node = root;
        for (char c : sentence) {
            int index = (c == ' ') ? 26 : c - 'a';
            if (node->next[index] == nullptr) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
        }
        node->times += times;
    }
    
    void dfs(TrieNode* node, string s, vector<Node>& candidates) {
        if (node->times) {
            candidates.emplace_back(node->times, s);
        }
        
        for (int i = 0; i < 26; ++i) {
            if (node->next[i]) {
                dfs(node->next[i], s + char('a' + i), candidates);
            }
        }
        
        if (node->next[26]) {
            dfs(node->next[26], s + ' ', candidates);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */


struct Node {
    int times;
    string sentence;
    Node(int t, string s) : times(t), sentence(s) {}
    bool operator < (Node node) const {
        if (times == node.times) {
            return sentence < node.sentence;
        }
        return times > node.times;
    }
};

class TrieNode {
public:
    TrieNode() {
        memset(next, NULL, sizeof(next));
    }
    TrieNode* next[27];
    unordered_map<string, int> strMap;
    ~TrieNode() {
        for (auto p : next) {
            if (p) {
                delete p;
            }
        }
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        currNode = root;
        curr = "";
        for (int i = 0; i < sentences.size(); ++i) {
            insert(root, sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(root, curr, 1);
            curr = "";
            currNode = root;
            return{};
        }
        else {
            curr += c;
            int index = (c == ' ') ? 26 : c - 'a';
            if (currNode == nullptr || currNode->next[index] == nullptr) {
                currNode = nullptr;
                return{};
            }
            currNode = currNode->next[index];
            priority_queue<Node> pq;
            for (auto it = currNode->strMap.begin(); it != currNode->strMap.end(); ++it) {
                pq.emplace(it->second, it->first);
                if (pq.size() > 3) {
                    pq.pop();
                }
            }

            vector<string> result;
            while (!pq.empty()) {
                result.push_back(pq.top().sentence);
                pq.pop();
            }
            reverse(result.begin(), result.end());
            return result;
        }
    }

    ~AutocompleteSystem() {
        delete root;
    }
private:
    TrieNode* root;
    string curr;
    TrieNode* currNode;
    void insert(TrieNode* root, string sentence, int times) {
        TrieNode* node = root;
        for (char c : sentence) {
            int index = (c == ' ') ? 26 : c - 'a';
            if (node->next[index] == nullptr) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
            node->strMap[sentence] += times;
        }
    }
};

/**
* Your AutocompleteSystem object will be instantiated and called as such:
* AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
* vector<string> param_1 = obj.input(c);
*/

struct Node {
    int times;
    string sentence;
    Node(int t, string s): times(t), sentence(s) {}    
};

struct cmp {
    bool operator () (Node* n1, Node* n2) {
        if (n1->times == n2->times) {
            return n1->sentence > n2->sentence;
        }
        return n1->times < n2->times;
    }
};

struct TrieNode {
    TrieNode() {
        memset(next, NULL, sizeof(next));
    }
    TrieNode* next[27];
    set<Node*, cmp> table;
    unordered_map<string, set<Node*>::iterator> strMap;
    ~TrieNode() {
        /*
        for (auto it = table.begin(); it != table.end(); ++it) {
            delete *it;
        }*/
        for (auto p : next) {
            if (p) {
                delete p;
            }
        }
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        currNode = root;
        curr = "";
        for (int i = 0; i < sentences.size(); ++i) {
            insert(root, sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(root, curr, 1);
            curr = "";
            currNode = root;
            return {};
        }
        else {
            curr += c;
            int index = (c == ' ') ? 26 : c - 'a';
            if (currNode == nullptr || currNode->next[index] == nullptr) {
                currNode = nullptr;
                return {};
            }
            currNode = currNode->next[index];
            vector<string> result;
            int i = 0;
            for (auto it = currNode->table.rbegin(); it != currNode->table.rend() && i < 3; ++it, ++i) {
                result.push_back((*it)->sentence);
            }
            return result;            
        }
    }
    
    ~AutocompleteSystem() {
        delete root;
    }

private:
    TrieNode* root;
    string curr;
    TrieNode* currNode;
    void insert(TrieNode* root, string sentence, int times) {
        TrieNode* node = root;
        for (char c : sentence) {
            int index = (c == ' ') ? 26 : c - 'a';
            if (node->next[index] == nullptr) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
            Node* n = nullptr;
            if (node->strMap.find(sentence) == node->strMap.end()) {
                n = new Node(times, sentence);
            }
            else {
                auto it = node->strMap[sentence];                
                n = new Node((*it)->times + times, sentence);
                node->table.erase(it);
            }
            node->strMap[sentence] = node->table.insert(n).first;
        }        
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
