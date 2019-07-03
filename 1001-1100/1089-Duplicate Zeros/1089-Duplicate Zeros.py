class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        zero = 0
        i = 0
        while i + zero < len(arr):
            if arr[i] == 0:
                zero += 1
            i += 1
        
        if i + zero > len(arr):
            arr[-1] = 0
            i -= 1
            zero -= 1
        
        i -= 1
        j = i + zero
        while j >= 0:
            if arr[i]:
                arr[j] = arr[i]
            else:
                arr[j] = 0
                j -= 1
                arr[j] = 0
            j -= 1
            i -= 1
