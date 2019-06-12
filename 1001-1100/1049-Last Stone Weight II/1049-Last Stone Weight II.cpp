class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<bool> dp(1 + sum);
        dp[0] = true;
        sum = 0;
        for (int stone : stones) {
            sum += stone;
            for (int i = sum; i >= stone; --i) {
                if (dp[i - stone]) {
                    dp[i] = true;
                }
            }
        }
        
        for (int i = sum / 2; i >= 0; --i) {
            if (dp[i]) {
                return sum - i - i;
            }
        }
        
        return -1;
    }
};
