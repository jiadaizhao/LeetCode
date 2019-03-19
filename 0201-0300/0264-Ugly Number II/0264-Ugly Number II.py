class Solution:
    def nthUglyNumber(self, n: int) -> int:
        p2 = p3 = p5 = 0
        ugly = [1] * n
        for i in range(1, n):
            ugly[i] = min(ugly[p2]*2, ugly[p3]*3, ugly[p5]*5)
            if ugly[p2]*2 == ugly[i]:
                p2 += 1
            if ugly[p3]*3 == ugly[i]:
                p3 += 1
            if ugly[p5]*5 == ugly[i]:
                p5 += 1
        return ugly[-1]
