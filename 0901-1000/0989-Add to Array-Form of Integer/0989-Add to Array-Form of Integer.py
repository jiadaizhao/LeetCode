class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        result = []
        i = len(A) - 1
        carry = 0
        while K or carry:
            s = carry + K % 10
            if i >= 0:
                s += A[i]
                i -= 1
            carry, s = divmod(s, 10)
            result.append(s)
            K //= 10
        while i >= 0:
            result.append(A[i])
            i -= 1
        return result[::-1]
