class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        diff = True
        while diff:
            curr = arr[:]
            diff = False
            for i in range(1, len(arr) - 1):
                if arr[i] < arr[i - 1] and arr[i] < arr[i + 1]:
                    curr[i] += 1
                    diff = True
                elif arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                    curr[i] -= 1
                    diff = True
            arr = curr
        return arr
