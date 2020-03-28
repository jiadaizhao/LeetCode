class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size());
        vector<int> path;
        dfs(nums, 0, path, used, result);
        return result;
    }
    
private:
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<bool>& used, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i] && (i == 0 || nums[i] != nums[i - 1] || used[i - 1])) {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(nums, start + 1, path, used, result);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};
