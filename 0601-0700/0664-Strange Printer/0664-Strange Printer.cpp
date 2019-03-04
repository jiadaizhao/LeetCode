class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> table(n, vector<int>(n));
        return dfs(s, 0, n - 1, table);
    }
    
private:
    int dfs(string& s, int l, int r, vector<vector<int>>& table) {
        if (l > r) {
            return 0;
        }
        if (table[l][r]) {
            return table[l][r];
        }
        
        int count = dfs(s, l + 1, r, table) + 1;
        for (int i = l + 1; i <= r; ++i) {
            if (s[i] == s[l]) {
                count = min(count, dfs(s, l + 1, i - 1, table) + dfs(s, i, r, table));
            }
        }
        return table[l][r] = count;
    }
};
