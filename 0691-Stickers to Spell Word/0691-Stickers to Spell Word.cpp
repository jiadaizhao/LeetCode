class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> table(n, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            for (char c : stickers[i]) {
                ++table[i][c - 'a'];
            }
        }
        
        lens[""] = 0;
        return dfs(target, table);
    }
    
private:
    unordered_map<string, int> lens;
    int dfs(string target, vector<vector<int>>& table) {
        if (lens.find(target) != lens.end()) {
            return lens[target];
        }
        
        vector<int> count(26);
        for (char c : target) {
            ++count[c - 'a'];
        }
        
        int minLen = -1;
        for (int i = 0; i < table.size(); ++i) {
            if (table[i][target[0] - 'a'] != 0) {
                string next;
                for (int j = 0; j < 26; ++j) {
                    if (count[j] - table[i][j] > 0) {
                        next += string(count[j] - table[i][j], 'a' + j);
                    }
                }
                int nextLen = dfs(next, table);
                if (nextLen != -1 && (minLen == -1 || nextLen + 1 < minLen)) {
                    minLen = nextLen + 1;
                }
            }
        }
        
        return lens[target] = minLen;
    }
};
