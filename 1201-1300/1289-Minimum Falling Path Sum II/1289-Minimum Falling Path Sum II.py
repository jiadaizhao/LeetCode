class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        min1 = min2 = -1
        for j in range(len(arr[0])):
            if min1 == -1 or arr[0][j] < arr[0][min1]:
                min2 = min1
                min1 = j
            elif min2 == -1 or arr[0][j] < arr[0][min2]:
                min2 = j
                
        for i in range(1, len(arr)):
            currMin1 = currMin2 = -1
            for j in range(len(arr[i])):
                if j == min1:
                    arr[i][j] += arr[i - 1][min2]
                else:
                    arr[i][j] += arr[i - 1][min1]
                    
                if currMin1 == -1 or arr[i][j] < arr[i][currMin1]:
                    currMin2 = currMin1
                    currMin1 = j
                elif currMin2 == -1 or arr[i][j] < arr[i][currMin2]:
                    currMin2 = j
                
            min1, min2 = currMin1, currMin2
        return arr[-1][min1]
