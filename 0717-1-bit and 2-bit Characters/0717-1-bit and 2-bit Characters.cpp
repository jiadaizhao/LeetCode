class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n == 1 || bits[n - 2] == 0) {
            return true;
        }
        vector<bool> dp(n);
        dp[0] = true;
        for (int i = 1; i < dp.size(); ++i) {
            if (bits[i - 1] == 0 && (dp[i - 1] || (i > 1 && dp[i - 2]))) {
                dp[i] = true;
            }
            else if (bits[i - 1] == 1 && i > 1 && bits[i - 2] == 1 && dp[i - 2]){
                dp[i] = true;
            }
        }
                
        return dp[n - 1] && !dp[n - 2];
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n - 1) {
            if (bits[i] == 0) {
                ++i;
            }
            else {
                i += 2;
            }
        }
        
        return i == n - 1;
    }
};
