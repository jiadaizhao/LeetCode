import collections
class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        cnts = collections.Counter()
        freqs = collections.Counter()
        maxFreq = maxEqual = 0
        for i, num in enumerate(nums):
            cnts[num] += 1
            freqs[cnts[num] - 1] -= 1
            freqs[cnts[num]] += 1
            maxFreq = max(maxFreq, cnts[num])
            if maxFreq == 1 or maxFreq * freqs[maxFreq] == i or (maxFreq - 1) * freqs[maxFreq - 1] + maxFreq == i + 1:
                maxEqual = i + 1

        return maxEqual
