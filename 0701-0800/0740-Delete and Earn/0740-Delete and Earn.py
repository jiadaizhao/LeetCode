class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        sums = [0] * 10001
        for num in nums:
            sums[num] += num
            
        prev = curr = 0
        for s in sums:
            next = max(curr, prev + s)
            prev = curr
            curr = next
        return curr

import collections
class Solution2:
    def deleteAndEarn(self, nums: List[int]) -> int:
        table = collections.Counter(nums)
        prev = None
        skip = take = 0
        for k in sorted(table):
            if k - 1 != prev:
                curr = max(take, skip) + k * table[k]
            else:
                curr = skip + k * table[k]
            skip = max(skip, take)
            take = curr
            prev = k
        
        return max(skip, take)


class Solution3:
    def deleteAndEarn(self, nums: List[int]) -> int:
        table = collections.Counter(nums)
        take = skip = 0
        prev = None
        for k in sorted(table):
            if k - 1 == prev:
                take, skip = skip + k * table[k], max(skip, take)
            else:
                take, skip = max(take, skip) + k * table[k], max(skip, take)
            prev = k
        return max(skip, take)
