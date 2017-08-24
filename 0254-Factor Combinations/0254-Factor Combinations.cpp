class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(2, n, path, result);
        return result;
    }
    
private:
    void dfs(int start, int n, vector<int>& path, vector<vector<int>>& result)
    {
        for (int i = start; i * i <=  n; ++i)
        {
            if (n % i == 0)
            {
                path.push_back(i);
                dfs(i, n / i, path, result);
                path.push_back(n / i);
                result.push_back(path);
                path.pop_back();
                path.pop_back();
            }
        }
    }
};
