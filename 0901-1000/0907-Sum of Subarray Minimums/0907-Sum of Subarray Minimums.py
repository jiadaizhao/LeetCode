class Solution:
    def sumSubarrayMins(self, A: List[int]) -> int:
        A.append(0)
        St = []
        total = 0
        MOD = 10 ** 9 + 7
        for i, a in enumerate(A):
            while St and A[St[-1]] > a:
                index = St.pop()
                left = St[-1] if St else -1
                total = (total + A[index] * (i - index) * (index - left)) % MOD
            St.append(i)
        return total
