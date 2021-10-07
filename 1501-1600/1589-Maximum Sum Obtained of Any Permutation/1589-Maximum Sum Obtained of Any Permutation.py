class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        n = len(nums)
        count = [0] * (n + 1)
        for start, end in requests:
            count[start] += 1
            count[end + 1] -= 1
        for i in range(1, n + 1):
            count[i] += count[i - 1]
        total = 0
        for c, num in zip(sorted(count[:-1]), sorted(nums)):
            total += c * num
        return total % (10 ** 9 + 7)
