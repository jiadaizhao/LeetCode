import bisect
import math
class Solution:
    def maxSumSubmatrix(self, matrix: 'List[List[int]]', k: 'int') -> 'int':
        m = len(matrix)
        n = len(matrix[0])
        maxSum = -math.inf

        for l in range(n):
            sums = [0] * m
            for r in range(l, n):
                table = [0]
                presum = 0
                for i in range(m):
                    sums[i] += matrix[i][r]
                    presum += sums[i]
                    index = bisect.bisect_left(table, presum - k)
                    if index != len(table):
                        maxSum = max(maxSum, presum - table[index])
                        if maxSum == k:
                            return k
                    bisect.insort_left(table, presum)                

        return maxSum


class Solution2:
    def maxSumSubmatrix(self, matrix: 'List[List[int]]', k: 'int') -> 'int':
        m = len(matrix)
        n = len(matrix[0])
        maxSum = -math.inf
        presum = [[0] * (n + 1) for _ in range(m)]
        for i in range(m):
            for j in range(n):
                presum[i][j + 1] = presum[i][j] + matrix[i][j]


        for l in range(n):
            for r in range(l, n):
                curr = 0
                table = [0]
                for i in range(m):
                    curr += presum[i][r + 1] - presum[i][l]
                    index = bisect.bisect_left(table, curr - k)
                    if index != len(table):
                        maxSum = max(maxSum, curr - table[index])
                        if maxSum == k:
                            return k
                    bisect.insort_left(table, curr)                

        return maxSum
