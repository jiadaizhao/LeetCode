class Solution:
    def countBits(self, num: int) -> List[int]:
        result = [0] * (1 + num)
        for i in range(1, 1 + num):
            result[i] = result[i&(i - 1)] + 1
        return result
