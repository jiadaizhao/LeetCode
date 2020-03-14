class Solution {
public:
    string sortString(string s) {
        vector<int> table(26);
        for (char c : s) {
            ++table[c - 'a'];
        }
        string result;
        while (result.size() < s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (table[i] > 0) {
                    result += 'a' + i;
                    --table[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (table[i] > 0) {
                    result += 'a' + i;
                    --table[i];
                }
            }
        }
        
        return result;
    }
};


class Solution2 {
public:
    string sortString(string s) {
        unordered_map<char, int> table;
        for (char c : s) {
            ++table[c];
        }
        vector<pair<char, int>> chs;
        for (auto p : table) {
            chs.push_back({p.first, p.second});
        }
        sort(chs.begin(), chs.end());
        string result;
        while (result.size() < s.size()) {
            for (int i = 0; i < chs.size(); ++i) {
                if (chs[i].second > 0) {
                    result += chs[i].first;
                    chs[i].second -= 1;
                }
            }
            for (int i = chs.size() - 1; i >= 0; --i) {
                if (chs[i].second > 0) {
                    result += chs[i].first;
                    chs[i].second -= 1;
                }
            }
        }
        
        return result;
    }
};
