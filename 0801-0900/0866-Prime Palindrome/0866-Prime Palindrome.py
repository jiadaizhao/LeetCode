class Solution:
    def primePalindrome(self, N: int) -> int:
        if 8 <= N <= 11:
            return 11
        def isPrime(num):
            if num < 2 or num % 2 == 0:
                return num == 2
            return all(num % i for i in range(3, int(num**0.5) + 1, 2))
        
        for i in range(1, 100000):
            left = str(i)
            right = left[-2::-1]
            num = int(left + right)
            if num >= N and isPrime(num):
                return num
        return -1
