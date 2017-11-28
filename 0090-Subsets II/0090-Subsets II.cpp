class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, path, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        result.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i] != nums[i - 1]) {
                path.push_back(nums[i]);
                dfs(nums, i + 1, path, result);
                path.pop_back();
            }
        }
    }
};
