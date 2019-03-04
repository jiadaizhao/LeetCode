class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        if (nums.size() == 0) {
            result.push_back(path);
            return result;
        }
        
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size());
        dfs(nums, path, used, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& result) {
        if (nums.size() == path.size()) {
            result.push_back(path);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path, used, result);
            path.pop_back();
            used[i] = false;
        }
    }
};
