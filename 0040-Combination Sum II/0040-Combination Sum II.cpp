class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.size() == 0)
        {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, 0, 0, target, path, result);
        return result;
    }
    
private:
    void dfs(vector<int>& candidates, int start, int sum, int target, vector<int>& path, vector<vector<int>>& result)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i)
        {
            if (candidates[i] + sum > target)
            {
                break;
            }
            
            if (i != start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i], target, path, result);
            path.pop_back();
        }
    }
};
