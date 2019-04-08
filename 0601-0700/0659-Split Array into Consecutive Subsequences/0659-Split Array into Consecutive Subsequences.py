import collections
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        freq = collections.Counter(nums)
        app = collections.Counter()
        for num in nums:
            if freq[num] == 0:
                continue
            if app[num] > 0:
                app[num] -= 1
                app[num + 1] += 1
            elif freq[num + 1] > 0 and freq[num + 2] > 0:
                freq[num + 1] -= 1
                freq[num + 2] -= 1
                app[num + 3] += 1
            else:
                return False
            freq[num] -= 1
        return True
