class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        minDiff = arr[1] - arr[0]
        result = [[arr[0], arr[1]]]
        for i in range(2, len(arr)):
            diff = arr[i] - arr[i - 1]
            if diff < minDiff:
                minDiff = diff
                result = [[arr[i - 1], arr[i]]]
            elif diff == minDiff:
                result.append([arr[i - 1], arr[i]])
        
        return result
