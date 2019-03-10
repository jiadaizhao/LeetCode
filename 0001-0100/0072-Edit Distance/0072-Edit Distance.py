class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [i for i in range(1 + len(word2))]
        for i in range(1, 1 + len(word1)):
            temp = [0] * (1 + len(word2))
            temp[0] = i
            for j in range(1, 1 + len(word2)):
                if word1[i - 1] == word2[j - 1]:
                    temp[j] = dp[j - 1]
                else:
                    temp[j] = 1 + min(dp[j], temp[j - 1], dp[j - 1])
            dp = temp
        return dp[-1]
