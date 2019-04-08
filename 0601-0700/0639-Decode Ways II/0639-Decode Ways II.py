class Solution:
    def numDecodings(self, s: str) -> int:
        MOD = 1000000007
        dp = [0] * (1 + len(s))
        dp[0] = 1
        for i in range(1, len(dp)):
            if s[i - 1] == '*':
                dp[i] = dp[i - 1]*9 % MOD
            elif s[i - 1] != '0':
                dp[i] = dp[i - 1]
                
            if i >= 2:
                if s[i - 2] == '*':
                    if s[i - 1] == '*':
                        dp[i] = (dp[i] + dp[i - 2]*15) % MOD
                    elif '0' <= s[i - 1] <= '6':
                        dp[i] = (dp[i] + dp[i - 2]*2) % MOD
                    else:
                        dp[i] = (dp[i] + dp[i - 2]) % MOD
                elif s[i - 2] == '1':
                    if s[i - 1] == '*':
                        dp[i] = (dp[i] + dp[i - 2]*9) % MOD
                    else:
                        dp[i] = (dp[i] + dp[i - 2]) % MOD
                elif s[i - 2] == '2':
                    if s[i - 1] == '*':
                        dp[i] = (dp[i] + dp[i - 2]*6) % MOD
                    elif '0' <= s[i - 1] <= '6':
                        dp[i] = (dp[i] + dp[i - 2]) % MOD
        return dp[-1]

# Optimize to O(1) space
class Solution2:
    def numDecodings(self, s: str) -> int:
        MOD = 1000000007
        dp0 = 1
        if s[0] == '*':
            dp1 = 9
        elif s[0] != '0':
            dp1 = 1
        else:
            dp1 = 0
            
        for i in range(2, len(s) + 1):
            if s[i - 1] == '*':
                dp2 = dp1 * 9 % MOD
            elif s[i - 1] != '0':
                dp2 = dp1
            else:
                dp2 = 0
                
            if s[i - 2] == '*':
                if s[i - 1] == '*':
                    dp2 = (dp2 + dp0 * 15) % MOD
                elif '0' <= s[i - 1] <= '6':
                    dp2 = (dp2 + dp0 * 2) % MOD
                else:
                    dp2 = (dp2 + dp0) % MOD
            elif s[i - 2] == '1':
                if s[i - 1] == '*':
                    dp2 = (dp2 + dp0 * 9) % MOD
                else:
                    dp2 = (dp2 + dp0) % MOD
            elif s[i - 2] == '2':
                if s[i - 1] == '*':
                    dp2 = (dp2 + dp0 * 6) % MOD
                elif '0' <= s[i - 1] <= '6':
                    dp2 = (dp2 + dp0) % MOD
            
            dp0 = dp1
            dp1 = dp2
        return dp1
