class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        if ((stones.size() -1) % (K - 1)) {
            return -1;
        }

        vector<int> presum(1 + stones.size());
        for (int i = 0; i < stones.size(); ++i) {
            presum[i + 1] = presum[i] + stones[i];
        }

        vector<vector<int>> dp(stones.size(), vector<int>(stones.size()));
        for (int l = K; l <= stones.size(); ++l) {
            for (int start = 0; start <= stones.size() - l; ++start) {
                int end = start + l - 1;
                dp[start][end] = INT_MAX;
                for (int mid = start; mid < end; mid += K - 1) {
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end]);
                }

                if ((end - start) % (K - 1) == 0) {
                    dp[start][end] += presum[end + 1] - presum[start];
                }
            }
        }

        return dp[0].back();
    }
};
