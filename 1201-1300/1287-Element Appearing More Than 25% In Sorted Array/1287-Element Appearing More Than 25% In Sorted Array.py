import bisect
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        for i in [n // 4, n // 2, 3 * n // 4]:
            i1 = bisect.bisect_left(arr, arr[i])
            if i1 == n or arr[i1] != arr[i]:
                continue
            i2 = bisect.bisect_right(arr, arr[i])
            if i2 - i1 > n // 4:
                return arr[i]
        return -1
