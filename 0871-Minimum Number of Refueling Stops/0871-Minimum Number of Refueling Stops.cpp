// DP
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {       
        int n = stations.size();
        vector<long long> dp(1 + n);
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j >= 1; --j) {
                if (dp[j - 1] >= stations[i][0]) {
                    dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
                }
                else {
                    break;
                }
            }
        }
        
        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) {
                return i;
            }
        }
        
        return -1;
    }
};

// Greedy
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {       
        priority_queue<int> pq;
        int dist = startFuel, stop = 0, i = 0, n = stations.size();        
        while (dist < target) {
            ++stop;
            while (i < n && dist >= stations[i][0]) {
                pq.push(stations[i++][1]);
            }
            
            if (pq.empty()) {
                return -1;
            }
            
            dist += pq.top();
            pq.pop();
        }
        return stop;
    }
};
