class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        n = len(arr)
        median = arr[(n - 1) // 2]
        left = 0
        right = n - 1
        result = [0] * k
        for i in range(k):
            if median - arr[left] > arr[right] - median:
                result[i] = arr[left]
                left += 1
            else:
                result[i] = arr[right]
                right -= 1
        return result
