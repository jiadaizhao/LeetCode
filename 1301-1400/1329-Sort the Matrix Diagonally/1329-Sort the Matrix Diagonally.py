import collections
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        table = collections.defaultdict(list)
        m, n = len(mat), len(mat[0])
        for i in range(m):
            for j in range(n):
                table[i - j].append(mat[i][j])
        
        for nums in table.values():
            nums.sort(reverse=True)

        result = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                result[i][j] = table[i - j].pop()
        return result
