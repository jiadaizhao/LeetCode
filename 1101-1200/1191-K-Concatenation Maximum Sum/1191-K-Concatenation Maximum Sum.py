class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        maxSum = 0
        s1 = s2 = s3 = total = 0
        maxPrefix = maxSuffix = 0
        for i, a in enumerate(arr):
            if s1 < 0:
                s1 = 0
            s1 += a
            s2 += a
            s3 += arr[~i]
            total += a
            maxSum = max(maxSum, s1)
            maxPrefix = max(maxPrefix, s2)
            maxSuffix = max(maxSuffix, s3)

        return max(maxSum, total * k, maxPrefix + maxSuffix + (max(total, 0) * (k - 2) if k > 2 else 0)) % (10 ** 9 + 7)


class Solution2:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        def kadane(arr):
            s = maxSum = 0
            for a in arr:
                if s < 0:
                    s = 0
                s += a
                maxSum = max(maxSum, s)
            return maxSum

        return (kadane(arr + arr) + max(sum(arr), 0) * (k - 2) if k > 1 else kadane(arr)) % (10 ** 9 + 7)
