class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for i in range(len(A)):
            A[i] = list(map(lambda x: 1 - x, A[i]))[::-1]
        return A

class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for row in A:
            for j in range((len(row) + 1)//2):
                row[j], row[~j] = row[~j]^1, row[j]^1
        return A
