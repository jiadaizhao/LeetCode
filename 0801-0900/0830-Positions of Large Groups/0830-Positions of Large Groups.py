class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        result = []
        i = 0
        while i < len(S):
            start = i
            while i < len(S) and S[i] == S[start]:
                i += 1
            if i - start >= 3:
                result.append([start, i - 1])
        return result
