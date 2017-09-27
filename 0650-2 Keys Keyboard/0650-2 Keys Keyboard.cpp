// DP
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(1 + n, INT_MAX);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j * 2 <= i; ++j)
            {
                if (i % j == 0)
                {
                    dp[i] = min(dp[i], dp[j] + i / j);
                }                
            }            
        }
        
        return dp[n];
    }
};

// Greedy
class Solution {
public:
    int minSteps(int n) {
        int s = 0;
        for (int i = 2; i <= n; ++i)
        {
            while (n % i == 0)
            {
                s += i;
                n /= i;
            }
        }
        
        return s;
    }
};
