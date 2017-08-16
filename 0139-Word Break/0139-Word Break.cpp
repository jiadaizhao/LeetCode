class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if (n == 0)
        {
            return true;
        }
        
        vector<bool> dp(1 + n);
        dp[0] = true;
        int maxLen = 0;
        unordered_set<string> wordSet;
        for (string w : wordDict)
        {
            maxLen = max(maxLen, (int)(w.size()));
            wordSet.insert(w);
        }
        
        for (int j = 1; j <= n; ++j)
        {
            for (int i = j - 1; i >= j - maxLen && i >= 0; --i)
            {
                if (wordSet.find(s.substr(i, j - i)) != wordSet.end() && dp[i])
                {
                    dp[j] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
