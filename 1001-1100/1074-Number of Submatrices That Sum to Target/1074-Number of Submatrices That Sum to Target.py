import collections
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        presum = [[0] * (len(matrix[0]) + 1) for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                presum[i][j + 1] = presum[i][j] + matrix[i][j]

        total = 0
        for j in range(len(matrix[0])):
            for i in range(j + 1):
                curr = 0
                table = collections.Counter([0])
                for k in range(len(matrix)):
                    curr += presum[k][j + 1] - presum[k][i]
                    total += table[curr - target]
                    table[curr] += 1

        return total
