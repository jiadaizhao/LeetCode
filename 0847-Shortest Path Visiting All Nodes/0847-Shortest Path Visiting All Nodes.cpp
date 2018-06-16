class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; ++i) {
            dp[i][1 << i] = 0;
            Q.emplace(i, 1 << i);
        }
        
        while (!Q.empty()) {
            int curr = Q.front().first;
            int mask = Q.front().second;
            Q.pop();
            for (int next : graph[curr]) {
                int nextMask = mask | (1 << next); 
                if (dp[next][nextMask] > dp[curr][mask] + 1) {
                    dp[next][nextMask] = dp[curr][mask] + 1;
                    Q.emplace(next, nextMask);
                }
            }
        }
        
        int minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minLen = min(minLen, dp[i].back());
        }
        return minLen;
    }
};
