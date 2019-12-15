class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        table = [0] * 10001
        for row in mat:
            for val in row:
                table[val] += 1
                if table[val] == len(mat):
                    return val
        return -1
