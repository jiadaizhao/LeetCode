class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        
        int k = costs[0].size();
        int min1 = -1, min2 = -1;
        int premin1 = -1, premin2 = -1;
        for (int i = 0; i < n; ++i) {
            min1 = -1;
            min2 = -1;
            for (int j = 0; j < k; ++j) {
                if (premin1 != j) {
                    if (i > 0) {
                        costs[i][j] += costs[i - 1][premin1];
                    }
                }
                else {
                    costs[i][j] += costs[i - 1][premin2];
                }
                
                if (min1 == -1 || costs[i][j] < costs[i][min1]) {
                    min2 = min1;
                    min1 = j;
                }
                else if (min2 == -1 || costs[i][j] < costs[i][min2]) {
                    min2 = j;
                }
            }
            premin1 = min1;
            premin2 = min2;
        }
        
        return costs[n - 1][min1];
    }
};
