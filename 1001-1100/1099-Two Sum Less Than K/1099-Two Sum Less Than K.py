class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        A.sort()
        maxS = -1 
        start = 0
        end = len(A) - 1
        while start < end:
            curr = A[start] + A[end]
            if curr >= K:
                end -= 1
            else:
                maxS = max(maxS, curr)
                start += 1
        return maxS
