class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int n = s.size();
        if (n == 0) {
            return result;
        }
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }
        
        vector<string> path;
        dfs(s, 0, path, palindrome, result);
        return result;
    }
    
private:
    void dfs(string s, int start, vector<string>& path, vector<vector<bool>>& palindrome, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = start; i < s.size(); ++i) {
            if (palindrome[start][i]) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, path, palindrome, result);
                path.pop_back();
            }
        }
    }
};
