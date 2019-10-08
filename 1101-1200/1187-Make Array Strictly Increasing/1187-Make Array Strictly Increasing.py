import collections, math, bisect
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort();
        states = {-1 : 0}
        for a in arr1:
            temp = collections.defaultdict(lambda : math.inf)
            for key in states:
                if a > key:
                    temp[a] = min(temp[a], states[key])
                index = bisect.bisect_right(arr2, key)
                if index < len(arr2):
                    temp[arr2[index]] = min(temp[arr2[index]], states[key] + 1)
            states = temp
        return min(states.values()) if states else -1
