class Solution:
    def orderlyQueue(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        if K > 1:
            return ''.join(sorted(S))
        minS = S
        for i in range(1, len(S)):
            minS = min(minS, S[i:] + S[0:i])
        return minS
