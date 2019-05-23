class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        m = len(A)
        n = len(A[0])
        sortedRow = [False] * (m - 1)
        count = sortedNum = 0
        for j in range(n):
            temp = sortedRow[:]
            num = 0
            for i in range(m - 1):
                if not sortedRow[i]:
                    if A[i][j] > A[i + 1][j]:
                        count += 1
                        break
                    elif A[i][j] < A[i + 1][j]:
                        temp[i] = True
                        num += 1
            else:
                sortedRow = temp
                sortedNum += num
                if sortedNum == m - 1:
                    break                 
        
        return count
