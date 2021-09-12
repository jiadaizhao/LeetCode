import math
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        table = {0 : -1}
        curr = 0
        for i, a in enumerate(arr):
            curr += a
            table[curr] = i
        curr = 0
        left = result = math.inf
        for i, a in enumerate(arr):
            curr += a
            if curr - target in table:
                left = min(left, i - table[curr - target])
            if left < math.inf and curr + target in table:
                result = min(result, table[curr + target] - i + left)
        return result if result < math.inf else -1
