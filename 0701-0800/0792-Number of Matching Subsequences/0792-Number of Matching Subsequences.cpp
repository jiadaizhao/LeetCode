class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> table(26);
        for (int i = 0; i < S.size(); ++i) {
            table[S[i] - 'a'].push_back(i);
        }
        
        int count = 0;
        for (string word : words) {
            int index = -1;
            bool flag = true;
            for (char c : word) {
                auto it = upper_bound(table[c - 'a'].begin(), table[c - 'a'].end(), index);
                if (it == table[c - 'a'].end()) {
                    flag = false;
                    break;
                }
                else {
                    index = *it;
                }                
            }
            if (flag) {
                ++count;
            }
        }
        return count;
    }
};

// Time Complexity: O(S.length + sum(words[i].length). 

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<pair<int, int>> table[26];
        for (int i = 0; i < words.size(); ++i) {
            table[words[i][0] - 'a'].emplace_back(i, 0);
        }
        
        int count = 0;
        for (char c : S) {
            auto p = table[c - 'a'];
            table[c - 'a'].clear();
            for (auto it : p) {
                ++it.second;
                if (it.second == words[it.first].size()) {
                    ++count;
                }
                else {
                    table[words[it.first][it.second] - 'a'].emplace_back(it);
                }
            }
        }
        return count;
    }
};
