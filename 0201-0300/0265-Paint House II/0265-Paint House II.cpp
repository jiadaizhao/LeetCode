class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        
        int k = costs[0].size();
        int min1 = -1, min2 = -1;
        for (int i = 0; i < n; ++i) {
            int currMin1 = -1, currMin2 = -1;
            for (int j = 0; j < k; ++j) {
                if (min1 != j) {
                    if (i > 0) {
                        costs[i][j] += costs[i - 1][min1];
                    }
                }
                else {
                    costs[i][j] += costs[i - 1][min2];
                }
                
                if (currMin1 == -1 || costs[i][j] < costs[i][currMin1]) {
                    currMin2 = currMin1;
                    currMin1 = j;
                }
                else if (currMin2 == -1 || costs[i][j] < costs[i][currMin2]) {
                    currMin2 = j;
                }
            }
            min1 = currMin1;
            min2 = currMin2;
        }
        
        return costs[n - 1][min1];
    }
};
