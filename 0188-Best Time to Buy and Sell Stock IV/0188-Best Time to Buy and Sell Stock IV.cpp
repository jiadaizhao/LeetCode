class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int n = s.size();
        if (n < 10)
        {
            return result;
        }
        unordered_map<string, int> table;
        for (int i = 0; i < n - 9; ++i)
        {
            string str = s.substr(i, 10);
            if (table[str]++ == 1)
            {
                result.push_back(str);
            }
        }
        
        return result;
    }
};

// Optimize space
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2)
        {
            int sum = 0;
            for (int i = 1; i < n; ++i)
            {
                int diff = prices[i] - prices[i - 1];
                if (diff > 0)
                {
                    sum += diff;
                }
            }
            
            return sum;
        }
        
        vector<int> dp(n);
        for (int i = 1; i <= k; ++i)
        {
            int localMax = dp[0] - prices[0];
            vector<int> temp(n);
            for (int j = 1; j < n; ++j)
            {
                temp[j] = max(temp[j - 1], prices[j] + localMax);
                localMax = max(localMax, dp[j] - prices[j]);
            }
            dp = temp;
        }
        
        return dp[n - 1];    
    }
};
