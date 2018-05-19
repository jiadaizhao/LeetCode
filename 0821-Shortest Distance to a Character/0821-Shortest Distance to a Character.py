class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        n = len(S)
        result = []
        prev = -n
        for i, c in enumerate(S):
            if c == C:
                prev = i
            result.append(i - prev)
        
        prev = n * 2
        for i in range(n - 1, -1, -1):
            if S[i] == C:
                prev = i
            result[i] = min(result[i], prev - i)
        return result
