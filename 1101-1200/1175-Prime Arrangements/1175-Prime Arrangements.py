class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        if n == 1:
            return 1
        prime = [True] * (1 + n)
        count = 1
        for i in range(3, n + 1, 2):
            if prime[i]:
                count += 1
                for j in range(i * i, n + 1, i):
                    prime[j] = False

        MOD = 10 ** 9 + 7
        def fac(num):
            result = 1
            for i in range(2, num + 1):
                result = result * i % MOD
            return result
        
        return fac(count) * fac(n - count) % MOD
