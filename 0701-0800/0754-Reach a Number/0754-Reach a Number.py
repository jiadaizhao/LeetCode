class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        i = 0
        while target > 0:
            i += 1
            target -= i
        if target % 2 == 0:
            result = i
        elif i % 2 == 0:
            result = i + 1
        else:
            result = i + 2
        return result
