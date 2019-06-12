class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& x, string& y){return x.size() < y.size();});
        unordered_map<string, int> dp;
        int maxLen = 0;
        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); ++i) {
                string ss = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(ss)) {
                    dp[word] = max(dp[word], dp[ss] + 1);
                }               
            }
            maxLen = max(maxLen, dp[word]);
        }
        
        return maxLen;
    }
};
