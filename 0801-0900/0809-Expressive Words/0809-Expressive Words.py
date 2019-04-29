class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:
        count = 0
        for word in words:
            i = j = 0
            while i < len(S):
                if j < len(word) and S[i] == word[j]:
                    j += 1
                elif i > 0 and S[i] == S[i - 1] and i < len(S) - 1 and S[i] == S[i + 1]:
                    i += 1
                elif not (i > 1 and S[i] == S[i - 1] == S[i - 2]):
                    break
                i += 1
            if i == len(S) and j == len(word):
                count += 1
        return count
