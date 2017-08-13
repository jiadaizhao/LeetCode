// Using DFS
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, 0, path, result);
        
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result)
    {
        result.push_back(path);
        for (int i = start; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};

// Using bitmap
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int limit = 1 << n;
        vector<vector<int>> result;
        for (int i = 0; i < limit; ++i)
        {
            vector<int> path;
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    path.push_back(nums[j]);
                }
            }
            result.push_back(path);
        }
        
        return result;
    }
};
