class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wordSet = set()
        maxLen = 0
        for word in wordDict:
            wordSet.add(word)
            maxLen = max(maxLen, len(word))
        table = {}
        def dfs(s):
            if s not in table:
                result = []
                if s in wordSet:
                    result.append(s)
                for i in range(1, min(len(s), maxLen + 1)):
                    prefix = s[:i]
                    if prefix in wordSet:
                        result += [prefix + ' ' + suffix for suffix in dfs(s[i:])]
                table[s] = result
            return table[s]
        return dfs(s)
