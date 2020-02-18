class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        p1 = p2 = -1
        minDist = len(words)
        for i, word in enumerate(words):
            if word == word1:                
                if p2 != -1:
                    minDist = min(minDist, i - p2)
                p1 = i
            elif word == word2:
                if p1 != -1:
                    minDist = min(minDist, i - p1)
                p2 = i
            
        return minDist
