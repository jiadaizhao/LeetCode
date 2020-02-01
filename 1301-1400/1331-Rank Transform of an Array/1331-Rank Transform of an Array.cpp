class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<vector<int>> nums(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            nums[i] = {arr[i], i};
        }
        sort(nums.begin(), nums.end());
        vector<int> result(arr.size());
        int rank = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i][0] == nums[i - 1][0]) {
                result[nums[i][1]] = rank;
            }
            else {
                result[nums[i][1]] = ++rank;
            }
        }
        
        return result;
    }
};
