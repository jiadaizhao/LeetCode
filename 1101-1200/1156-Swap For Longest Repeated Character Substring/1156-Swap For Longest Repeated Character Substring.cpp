class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> table(26);
        vector<pair<char, int>> group;
        for (char c : text) {
            ++table[c - 'a'];
            if (group.size() && c == group.back().first) {
                ++group.back().second;
            }
            else {
                group.emplace_back(c, 1);
            }
        }
        
        int maxLen = 0;
        for (auto g : group) {
            maxLen = max(maxLen, min(table[g.first - 'a'], g.second + 1));
        }
        
        
        for (int i = 1; i < group.size() - 1; ++i) {
            if (group[i - 1].first == group[i + 1].first && group[i].second == 1) {
                maxLen = max(maxLen, min(table[group[i - 1].first - 'a'], group[i - 1].second + 1 + group[i + 1].second));
            }
        }
        
        return maxLen;
    }
};
