class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        result = []
        n = len(S)
        i = 0
        while i < n:
            start = i
            while i < n and S[i] == S[start]:
                i += 1
            if i - start >= 3:
                result.append([start, i - 1])
        return result
