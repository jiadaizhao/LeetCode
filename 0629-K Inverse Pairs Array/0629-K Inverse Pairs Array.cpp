class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> presum(1 + k);
        int MOD = 1000000007;
        for (int i = 1; i <= n; ++i)
        {
            vector<int> temp(1 + k);
            temp[0] = 1;
            for (int j = 1; j <= k; ++j)
            {
                int val = (presum[j] - ((j - i >= 0) ? presum[j - i] : 0) + MOD) % MOD;                
                temp[j] = (temp[j - 1] + val) % MOD;
            }
            presum = temp;
        }
        
        return (presum[k] - ((k > 0) ? presum[k - 1] : 0) + MOD) % MOD;
    }
};
