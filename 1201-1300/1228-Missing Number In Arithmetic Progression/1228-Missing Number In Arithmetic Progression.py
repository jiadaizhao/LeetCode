class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        for i in range(2, len(arr)):
            if arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]:
                return arr[i - 2] + arr[i] - arr[i - 1]
        return arr[0]


class Solution2:
    def missingNumber(self, arr: List[int]) -> int:
        diff = (arr[-1] - arr[0]) // len(arr)
        low, high = 0, len(arr)
        while low < high:
            mid = (low + high) // 2
            if arr[mid] == arr[0] + mid * diff:
                low = mid + 1
            else:
                high = mid
        return arr[0] + low * diff
