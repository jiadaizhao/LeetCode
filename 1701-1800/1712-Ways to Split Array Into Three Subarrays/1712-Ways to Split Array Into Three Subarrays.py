class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        n = len(nums)
        presum = [0] * (n + 1)
        for i, num in enumerate(nums):
            presum[i + 1] = presum[i] + num
        
        def search(leftSum, index, leftBoundary):
            start = index
            end = n - 2
            result = -1
            while start <= end:
                mid = (start + end) // 2
                midSum = presum[mid + 1] - presum[index]
                rightSum = presum[n] - presum[mid + 1]
                if leftSum <= midSum <= rightSum:
                    result = mid
                    if leftBoundary:
                        end = mid - 1
                    else:
                        start = mid + 1
                elif leftSum > midSum:
                    start = mid + 1
                else:
                    end = mid - 1
            return result
        
        result = 0
        for i in range(1, n - 1):
            leftSum = presum[i]
            if leftSum * 3 > presum[n]:
                break
            left = search(leftSum, i, True)
            if left == -1:
                continue
            right = search(leftSum, i, False)
            result = (result + right - left + 1) % MOD
        return result
