class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path = "";
        dfs(path, n, n, result);
        return result;
    }
    
private:
    void dfs(string& path, int left, int right, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(path);
            return;
        }
        
        if (left > 0) {
            path.push_back('(');
            dfs(path, left - 1, right, result);
            path.pop_back();
        }
        
        if (left < right) {
            path.push_back(')');
            dfs(path, left, right - 1, result);
            path.pop_back();
        }
    }
};
