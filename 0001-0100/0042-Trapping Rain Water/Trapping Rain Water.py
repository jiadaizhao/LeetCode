class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxLeft = maxRight = total = 0
        while left < right:
            if height[left] <= height[right]:
                total += max(maxLeft - height[left], 0)
                maxLeft = max(maxLeft, height[left])
                left += 1
            else:
                total += max(maxRight - height[right], 0)
                maxRight = max(maxRight, height[right])
                right -= 1
        return total
