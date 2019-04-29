class Solution:
    def longestMountain(self, A: List[int]) -> int:
        left = maxLen = 0
        while left < len(A):
            mid = left
            while mid < len(A) - 1 and A[mid + 1] > A[mid]:
                mid += 1
            if mid == left:
                left += 1
                continue

            right = mid
            while right < len(A) - 1 and A[right + 1] < A[right]:
                right += 1

            if right > mid:
                maxLen = max(maxLen, right - left + 1)
            left = right
        return maxLen
