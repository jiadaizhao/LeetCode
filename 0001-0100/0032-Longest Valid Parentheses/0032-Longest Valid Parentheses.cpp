class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        int left = 0, right = 0;
        int maxLen = 0;
        for (char c : s) {
            if (c == '(') {
                ++left;
            }
            else {
                ++right;
            }
            
            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            }
            else if (right > left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++right;
            }
            else {
                ++left;
            }
            
            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            }
            else if (left > right) {
                left = right = 0;
            }
        }
        
        return maxLen;
    }
};

// DP
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n);
        int maxNum = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;  
                }
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
                }
                maxNum = max(maxNum, dp[i]);
            }
        }
        
        return maxNum;
    }
};