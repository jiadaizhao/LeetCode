class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> presum(1 + n);
        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + piles[i];
        }

        cache = vector<vector<int>>(n, vector<int>(n, -1));
        return dfs(piles, 0, 1, presum);
    }

private:
    vector<vector<int>> cache;
    int dfs(vector<int>& piles, int start, int M, vector<int>& presum) {
        if (cache[start][M] != -1) {
            return cache[start][M];
        }
        if (start + 2 * M >= piles.size()) {
            cache[start][M] = presum.back() - presum[start];
        }
        else {
            int maxNum = 0;
            for (int X = 1; X <= M * 2; ++X) {
                int next = dfs(piles, start + X, max(X, M), presum);
                maxNum = max(maxNum, presum.back() - presum[start] - next);
            }
            cache[start][M] = maxNum;
        }
        return cache[start][M];
    }
};
