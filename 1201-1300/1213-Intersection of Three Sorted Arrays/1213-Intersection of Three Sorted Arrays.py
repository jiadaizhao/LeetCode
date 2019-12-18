class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        p1 = p2 = p3 = 0
        result = []
        while p1 < len(arr1) and p2 < len(arr2) and p3 < len(arr3):
            currMin = min(arr1[p1], arr2[p2], arr3[p3])
            if arr1[p1] == arr2[p2] == arr3[p3]:
                result.append(currMin)
            if arr1[p1] == currMin:
                p1 += 1
            if arr2[p2] == currMin:
                p2 += 1
            if arr3[p3] == currMin:
                p3 += 1
        return result
