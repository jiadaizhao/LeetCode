class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        dp = [0] * (len(books) + 1)
        for j in range(1, len(dp)):
            width, height = books[j - 1]
            dp[j] = dp[j - 1] + height
            for i in range(j - 1, 0, -1):
                width += books[i - 1][0]
                if width <= shelf_width:
                    height = max(height, books[i - 1][1])
                    dp[j] = min(dp[j], dp[i - 1] + height)
                else:
                    break

        return dp[-1]
