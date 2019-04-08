class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        result = [[0]*len(M[0]) for _ in range(len(M))]
        for i in range(len(M)):
            for j in range(len(M[i])):
                sum = M[i][j]
                count = 1
                for ni, nj in (i-1, j-1), (i-1, j), (i-1, j+1), (i, j-1), (i, j+1), (i+1, j-1), (i+1, j), (i+1, j+1):
                    if 0 <= ni < len(M) and 0 <= nj < len(M[0]):
                        count += 1
                        sum += M[ni][nj]
                result[i][j] = sum // count
        return result
