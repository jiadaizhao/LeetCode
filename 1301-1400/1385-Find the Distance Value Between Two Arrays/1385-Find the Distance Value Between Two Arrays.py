class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr1.sort()
        arr2.sort()
        i = j = count = 0
        while i < len(arr1) and j < len(arr2):
            if arr1[i] > arr2[j] + d:
                j += 1
            else:
                if arr1[i] < arr2[j] - d:
                    count += 1
                i += 1
        count += len(arr1) - i
        return count
