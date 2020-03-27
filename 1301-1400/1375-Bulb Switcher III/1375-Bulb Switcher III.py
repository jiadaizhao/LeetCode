class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        right = num = 0
        for i, l in enumerate(light):
            right = max(right, l)
            if right == i + 1:
                num += 1
        return num
