class TrieNode {
public:
    TrieNode() {
        memset(next, NULL, sizeof(next));
        isEnd = false;
    };

    ~TrieNode() {
        for (TrieNode* p : next) {
            if (p) delete p;
        }
    }

    TrieNode* next[27];
    bool isEnd;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), [](string &s1, string &s2){return s1.size() < s2.size();});
        TrieNode* root = new TrieNode();
        vector<string> result;
        for (string f : folder) {
            TrieNode* curr = root;
            bool subfolder = false;
            for (int i = 0; i < f.size(); ++i) {
                int index = (f[i] == '/') ? 26 : f[i] - 'a';
                if (curr->next[index] == nullptr) {
                    curr->next[index] = new TrieNode();
                }
                curr = curr->next[index];
                if (curr->isEnd && f[i + 1] == '/') {
                    subfolder = true;
                    break;
                }
            }

            if (!subfolder) {
                result.push_back(f);
                curr->isEnd = true;
            }
        }

        return result;
    }
};
