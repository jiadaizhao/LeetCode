class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        dp = [[0] * (1 + len(str2)) for _ in range(1 + len(str1))]
        for j in range(1, 1 + len(str2)):
            dp[0][j] = j
            
        for i in range(1, 1 + len(str1)):
            dp[i][0] = i
            for j in range(1, 1 + len(str2)):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1])
                    
        result = [''] * dp[-1][-1]
        i = len(str1)
        j = len(str2)
        k = dp[-1][-1] - 1
        while i > 0 and j > 0:
            if str1[i - 1] == str2[j - 1]:
                result[k] = str1[i - 1]
                i -= 1
                j -= 1
            elif dp[i - 1][j] < dp[i][j - 1]:
                result[k] = str1[i - 1]
                i -= 1
            else:
                result[k] = str2[j - 1]
                j -= 1
            k -= 1
            
        while i > 0:
            result[k] = str1[i - 1]
            i -= 1
            k -= 1
        
        while j > 0:
            result[k] = str2[j - 1]
            j -= 1
            k -= 1
        return ''.join(result)
