class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        prime = [True] * n
        count = 1
        for i in range(3, n, 2):
            if prime[i]:
                count += 1
                prime[i*i: n: i] = [False] * len(prime[i*i: n: i])
        return count
