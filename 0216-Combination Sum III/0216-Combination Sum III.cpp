class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (n <= 0 || n > 45 || k <= 0)
        {
            return result;
        }
        
        vector<int> path;
        dfs(k, n, 1, 0, path, result);
        return result;
    }
    
private:
    void dfs(int k, int n, int start, int sum, vector<int>& path, vector<vector<int>>& result)
    {
        if (path.size() == k)
        {
            if (sum == n)
            {
                result.push_back(path);
            }
            
            return;
        }
        
        for (int i = start; i <= 9; ++i)
        {
            if (sum + i > n)
            {
                break;
            }
            
            path.push_back(i);
            dfs(k, n, i + 1, sum + i, path, result);
            path.pop_back();
        }
    }
};
