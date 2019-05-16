class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string s = to_string(N);
        int n = s.size();
        vector<int> dp(1 + n);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = D.size() - 1; j >= 0; --j) {
                if (D[j][0] == s[n - i]) {
                    dp[i] = dp[i - 1] + j * pow(D.size(), i - 1);
                    break;
                }
                else if (D[j][0] < s[n - i]) {
                    dp[i] = (j + 1) * pow(D.size(), i - 1);
                    break;
                }
            }
        }
        int total = dp[n];
        for (int i = 1; i < n; ++i) {
            total += pow(D.size(), i);
        }
        return total;
    }
};
