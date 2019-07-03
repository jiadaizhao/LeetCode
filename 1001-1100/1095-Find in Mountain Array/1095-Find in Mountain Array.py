# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

import math
class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        n = mountain_arr.length()
        low = 0
        high = n - 1
        while low < high:
            mid = (low + high) // 2
            curr = mountain_arr.get(mid)
            if mountain_arr.get(mid + 1) < curr:
                high = mid
            else:
                low = mid + 1

        peak = low

        def search(low, high, inc):
            while low <= high:
                mid = (low + high) // 2
                curr = mountain_arr.get(mid)
                if curr == target:
                    return mid
                elif curr < target:
                    if inc:
                        low = mid + 1
                    else:
                        high = mid - 1
                else:
                    if inc:
                        high = mid - 1
                    else:
                        low = mid + 1

            return math.inf

        result = min(search(0, peak, True), search(peak, n - 1, False))
        return result if result != math.inf else -1
