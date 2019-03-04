class Solution:
    def expressiveWords(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        count = 0
        n = len(S)
        for word in words:
            i = j = 0
            while i < n:
                if j < len(word) and S[i] == word[j]:
                    j += 1
                elif i > 0 and S[i] == S[i - 1] and i < n - 1 and S[i] == S[i + 1]:
                    i += 1
                elif not (i > 1 and S[i] == S[i - 1] == S[i - 2]):
                    break
                i += 1
            if i == n and j == len(word):
                count += 1
        return count

S = "heeellooo"
words = ["hello", "hi", "helo"]
sol = Solution()
count = sol.expressiveWords(S, words)
print(count)
