class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> debt;
        for (auto& t : transactions) {
            debt[t[0]] -= t[2];
            debt[t[1]] += t[2];
        }
        
        vector<int> account(debt.size());
        int len = 0;
        for (auto& d : debt) {
            if (d.second != 0) {
                account[len++] = d.second;
            }
        }
        
        if (len == 0) {
            return 0;
        }
        
        vector<int> dp(1 << len, INT_MAX / 2);
        for (int i = 1; i < dp.size(); ++i) {
            int sum = 0, count = 0;
            for (int j = 0; j < len; ++j) {
                if (1 << j & i) {
                    sum += account[j];
                    ++count;
                }
            }
            
            if (sum == 0) {
                dp[i] = count - 1;
                for (int j = 1; j < i; ++j) {
                    if (((i & j) == j) && dp[j] + dp[i - j] < dp[i]) {
                        dp[i] = dp[j] + dp[i - j];
                    }
                }
            }
        }
        
        return dp.back();
    }
};
