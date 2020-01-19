class Solution:
    def sumZero(self, n: int) -> List[int]:
        result = [i for i in range(1, n // 2 + 1)] + [-i for i in range(1, n // 2 + 1)]
        if n & 1:
            result.append(0)
        return result
