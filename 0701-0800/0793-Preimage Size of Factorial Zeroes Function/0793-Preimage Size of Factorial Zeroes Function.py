class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        low = 1
        high = 5 * (K + 1)
        def trailingZeros(num):
            count = 0
            while num >= 5:
                num //= 5
                count += num
            return count
        while low <= high:
            mid = (low + high) // 2
            count = trailingZeros(mid)
            if count > K:
                high = mid - 1
            elif count < K:
                low = mid + 1
            else:
                return 5
        return 0
