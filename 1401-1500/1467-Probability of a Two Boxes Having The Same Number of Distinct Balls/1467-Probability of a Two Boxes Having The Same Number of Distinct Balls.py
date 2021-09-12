import math
import itertools
class Solution:
    def getProbability(self, balls: List[int]) -> float:
        def multinomial(n):
            return math.factorial(sum(n))/math.prod([math.factorial(i) for i in n])
        k, n, Q = len(balls), sum(balls) // 2, 0
        arrays = [range(i + 1) for i in balls]
        t = list(itertools.product(*arrays))
        for i in range(len(t)):
            if sum(t[i]) == n and t[i].count(0) == t[-i-1].count(0):
                Q += multinomial(t[i]) * multinomial(t[-i-1]) 

        return Q / multinomial(list(balls))
