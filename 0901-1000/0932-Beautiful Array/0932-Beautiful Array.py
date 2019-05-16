class Solution:
    def beautifulArray(self, N: int) -> List[int]:
        result = [1]
        while len(result) < N:
            result = [i * 2 - 1 for i in result] + [i * 2 for i in result]
        return [i for i in result if i <= N]
