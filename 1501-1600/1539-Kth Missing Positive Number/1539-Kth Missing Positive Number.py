class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        target = 1
        i = 0
        while i < len(arr):
            if arr[i] == target:      
                i += 1
            else:
                k -= 1
                if k == 0:                    
                    return target
            target += 1
        return arr[-1] + k
