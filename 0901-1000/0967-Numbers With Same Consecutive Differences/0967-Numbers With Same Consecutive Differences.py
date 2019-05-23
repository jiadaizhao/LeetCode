class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        curr = list(range(1, 10))
        for _ in range(N - 1):
            next = []
            for x in curr:
                d = x % 10
                if d - K >= 0:
                    next.append(x * 10 + d - K)
                if K > 0 and d + K <= 9:
                    next.append(x * 10 + d + K)
            curr = next
        if N == 1:
            curr.append(0)
        return curr                   
