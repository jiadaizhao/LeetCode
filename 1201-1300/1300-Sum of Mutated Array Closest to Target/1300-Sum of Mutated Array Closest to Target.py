class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        low = 0
        high = max(arr)
        while low + 1 < high:
            mid = (low + high) // 2
            curr = sum(mid if a > mid else a for a in arr)
            if curr > target:
                high = mid
            elif curr < target:
                low = mid
            else:
                return mid
        
        sum1 = sum(low if a > low else a for a in arr)
        sum2 = sum(high if a > high else a for a in arr)
        if abs(sum1 - target) <= abs(sum2 - target):
            return low
        else:
            return high


class Solution2:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort(reverse=True)
        maxA = arr[0]
        while arr and target >= arr[-1] * len(arr):
            target -= arr.pop()
        return int(target / len(arr) + 0.5 - 0.1 / len(arr)) if arr else maxA
