class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
        low = 0
        high = 1
        def under(x):
            count = maxVal = left = p = q = 0
            for right in range(1, len(A)):
                while A[left] < x * A[right]:
                    left += 1
                count += left
                if left > 0:
                    if A[left - 1] / A[right] > maxVal:
                        maxVal = A[left - 1] / A[right]
                        p = A[left - 1]
                        q = A[right]
            return count, p, q
        while high - low > 1e-7:
            mid = (low + high) / 2
            count, p, q = under(mid)
            if count < K:
                low = mid
            else:
                result = [p, q]
                high = mid
        return result
