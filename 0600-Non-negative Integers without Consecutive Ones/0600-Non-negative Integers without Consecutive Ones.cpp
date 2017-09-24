class Solution {
public:
    int findIntegers(int num) {
        vector<int> dp(31);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < dp.size(); ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        int count = 0;
        int prevBit = 0;
        for (int bit = 30; bit >= 0; --bit)
        {
            if (num & (1 << bit))
            {
                count += dp[bit];
                if (prevBit == 1)
                {
                    return count;
                }
                prevBit = 1;
            }
            else
            {
                prevBit = 0;
            }
        }
        
        return count + 1;
    }
};
