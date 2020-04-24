class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        a, b = 1, 1
        while b < k:            
            a, b = b, a + b
        
        count = 0
        while k > 0:
            if b <= k:
                k -= b
                count += 1
            a, b = b - a, a
        return count
