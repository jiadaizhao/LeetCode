class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp(1 + m, vector<int>(1 + n));
        
        int maxArea = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                    maxArea = max(maxArea, dp[i][j] * dp[i][j]);
                }
            }
        }
        
        return maxArea;
    }
};

// Optimize space
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(1 + n);
        
        int maxArea = 0;
        for (int i = 1; i <= m; ++i) {
            vector<int> temp(1 + n);
            for (int j = 1; j <= n; ++j) {                
                if (matrix[i - 1][j - 1] == '1') {
                    temp[j] = 1 + min(dp[j], min(dp[j - 1], temp[j - 1]));
                    maxArea = max(maxArea, temp[j] * temp[j]);
                }                
            }
            dp = temp;
        }
        
        return maxArea;
    }
};
