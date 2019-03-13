class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set()
        maxLen = 0
        for word in wordDict:
            wordSet.add(word)
            maxLen = max(maxLen, len(word))
        dp = [False] * (1 + len(s))
        dp[0] = True
        for j in range(1, len(dp)):
            for i in range(j - 1, -1, -1):
                if j - i > maxLen:
                    break
                if s[i:j] in wordSet and dp[i]:
                    dp[j] = True
                    break
        return dp[-1]
