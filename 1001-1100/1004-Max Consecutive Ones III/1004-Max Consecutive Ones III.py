class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        maxLen = zero = start = 0
        for i, a in enumerate(A):
            if a == 0:
                zero += 1
            while zero > K:
                if A[start] == 0:
                    zero -= 1
                start += 1
            
            maxLen = max(maxLen, i - start + 1)
        return maxLen


class Solution2:
    def longestOnes(self, A: List[int], K: int) -> int:
        zero = start = 0
        for i, a in enumerate(A):
            if a == 0:
                zero += 1
            if zero > K:
                if A[start] == 0:
                    zero -= 1
                start += 1
            
        return len(A) - start
