class Solution:
    table = {}
    def soupServings(self, N):
        """
        :type N: int
        :rtype: float
        """
        if N >= 5000:
            return 1
        def soupServings(a, b):
            if a <= 0 and b <= 0:
                return 0.5
            if a <= 0:
                return 1
            if  b <= 0:
                return 0
            if (a, b) in self.table:
                return self.table[(a, b)]
            self.table[(a, b)] = 0.25 * (soupServings(a - 4, b) + soupServings(a - 3, b - 1) + \
                                         soupServings(a - 2, b - 2) + soupServings(a - 1, b - 3))
            return self.table[(a, b)]
        N = (N + 24) // 25
        return soupServings(N, N)
