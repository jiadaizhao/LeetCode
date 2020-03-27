class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        n = len(slices) // 3
        if n == 0:
            return max(slices)
        def maxSlice(start, end):
            dp0 = [0] * (n + 1)  # Two slices ago.
            dp1 = [0] * (n + 1)  # Previous slice.
            for i in range(start, end + 1):
                dp2 = [0] * (n + 1)
                for j in range(1, n + 1):
                    dp2[j] = max(dp1[j], dp0[j - 1] + slices[i])
                dp0, dp1 = dp1, dp2
            return dp1[-1]
        return max(maxSlice(0, len(slices) - 2), maxSlice(1, len(slices) - 1))
