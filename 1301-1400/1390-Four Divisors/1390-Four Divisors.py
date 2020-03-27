class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        total = 0
        for num in nums:
            i = 2
            d = 0
            while i * i <= num:
                if num % i == 0:
                    if d == 0:
                        d = i
                    else:
                        d = 0
                        break
                i += 1
            if d > 0 and d * d != num:
                total += 1 + d + num // d + num
        return total
