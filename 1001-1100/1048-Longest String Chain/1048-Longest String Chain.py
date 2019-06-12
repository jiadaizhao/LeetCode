class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=len)
        maxLen = 0
        dp = [1] * len(words)
        def isSubstring(s, t):
            i = j = 0
            while i < len(s) and j < len(t):
                if s[i] == t[j]:
                    i += 1
                j += 1

            return i == len(s)

        for j in range(len(words)):
            for i in range(j):
                if len(words[j]) == len(words[i]) + 1 and isSubstring(words[i], words[j]):
                    dp[j] = max(dp[j], 1 + dp[i])
            
            maxLen = max(maxLen, dp[j])
        return maxLen


class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        dp = {}
        for word in sorted(words, key=len):
            dp[word] = max(dp.get(word[:i] + word[i+1:], 0) + 1 for i in range(len(word)))

        return max(dp.values())
