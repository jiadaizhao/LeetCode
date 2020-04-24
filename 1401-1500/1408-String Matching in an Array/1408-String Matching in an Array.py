class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        words.sort(key=lambda x: len(x))
        result = []
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if words[i] in words[j]:
                    result.append(words[i])
                    break
        return result
