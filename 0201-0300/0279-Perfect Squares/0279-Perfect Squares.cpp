class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(1 + n);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        
        return dp[n];
    }
};

// Based on Legendre's three-square theorem
class Solution {
public:
    int numSquares(int n) {
        int root = sqrt(n);
        if (root * root == n) {
            return 1;
        }
        
        while (n % 4 == 0) {
            n /= 4;
        }
        
        if (n % 8 == 7) {
            return 4;
        }
        
        root = sqrt(n);
        for (int i = 1; i <= root; ++i) {
            int val = n - i * i;
            int temp = sqrt(val);
            if (temp * temp == val) {
                return 2;
            }
        }
        
        return 3;
    }
};
