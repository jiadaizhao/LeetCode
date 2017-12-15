// DP
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int maxLen = 1;
        int n = pairs.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};


// Greedy
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& p1, vector<int>& p2){return p1[1] < p2[1];});
        int n = pairs.size();
        int prev = pairs[0][1];
        int maxLen = 1;
        for (int i = 1; i < n; ++i) {
            if (pairs[i][0] > prev) {
                ++maxLen;
                prev = pairs[i][1];
            }
        }
        
        return maxLen;
    }
};
