import math
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        fac = math.factorial(n - 1)
        nums = [i for i in range(1, 1+n)]
        base = n - 1
        k -= 1
        result = [0] * n
        for i in range(n):
            index = k // fac
            k %= fac
            result[i] = str(nums[index])
            nums.pop(index)
            if base:
                fac //= base
                base -= 1
        return ''.join(result)
