import collections
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:        
        table = collections.Counter(letters)
        maxScore = 0
        for i in range(1 << len(words)):
            currScore = 0
            valid = True
            t = table.copy()
            for j in range(len(words)):
                if i & (1 << j):
                    for c in words[j]:
                        t[c] -= 1
                        currScore += score[ord(c) - ord('a')]
                        if t[c] < 0:
                            valid = False
                            break
                if not valid:
                    break
            if valid:                
                maxScore = max(maxScore, currScore)
                    
        return maxScore
