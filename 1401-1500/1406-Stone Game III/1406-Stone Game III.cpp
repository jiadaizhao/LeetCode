class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(1 + n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = INT_MIN;
            int take = 0;
            for (int j = i; j < min(i + 3, n); ++j) {
                take += stoneValue[j];
                dp[i] = max(dp[i], take - dp[j + 1]);
            }
        }
        
        if (dp[0] > 0) {
            return "Alice";
        }
        else if (dp[0] < 0) {
            return "Bob";
        }
        else {
            return "Tie";
        }
    }
};
