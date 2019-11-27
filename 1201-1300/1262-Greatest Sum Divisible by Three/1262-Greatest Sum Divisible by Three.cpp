class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for (int num : nums) {
            vector<int> temp(3);
            for (int i = 0; i < 3; ++i) {
                temp[(i + num) % 3] = max(dp[(i + num) % 3], dp[i] + num);    
            }
            dp = temp;
        }
        
        return dp[0];
    }
};
