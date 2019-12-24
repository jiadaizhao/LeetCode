class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n <= 0) {
            return result;
        }
        
        vector<int> path;
        dfs(1, n, k, path, result);
        return result;
    }

private:
    void dfs(int start, int n, int k, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        
        int curr = path.size();
        for (int i = start; i <= n + curr + 1 - k; ++i) {
            path.push_back(i);
            dfs(i + 1, n, k, path, result);
            path.pop_back();
        }
    }
};
