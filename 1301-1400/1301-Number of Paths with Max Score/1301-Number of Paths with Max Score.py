class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)
        MOD = 10 ** 9 + 7
        maxSum1 = [0] * n
        count1 = [0] * n
        count1[-1] = 1
        for j in range(n - 2, -1, -1):
            if board[-1][j] == 'X':
                break
            else:
                maxSum1[j] = maxSum1[j + 1] + int(board[-1][j])
                count1[j] = 1
   
        for i in range(n - 2, -1, -1):
            maxSum2 = [0] * n
            count2 = [0] * n
            if count1[-1] > 0 and board[i][-1] != 'X':
                maxSum2[-1] = maxSum1[-1] + int(board[i][-1])
                count2[-1] = 1
            for j in range(n - 2, -1, -1):
                if board[i][j] != 'X' and (count2[j + 1] or count1[j] or count1[j + 1]):
                    maxSum2[j] = maxSum2[j + 1]
                    count2[j] = count2[j + 1]
                    for nj in (j, j + 1):
                        if maxSum1[nj] > maxSum2[j]:
                            maxSum2[j] = maxSum1[nj]
                            count2[j] = count1[nj]
                        elif maxSum1[nj] == maxSum2[j]:
                            count2[j] = (count2[j] + count1[nj]) % MOD
                    if board[i][j] != 'E':
                        maxSum2[j] += int(board[i][j])
            maxSum1 = maxSum2
            count1 = count2
            
        return [maxSum1[0], count1[0]]
