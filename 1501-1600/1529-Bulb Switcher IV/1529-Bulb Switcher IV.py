class Solution:
    def minFlips(self, target: str) -> int:
        count = 0
        flag = 1
        for b in target:
            if b == "01"[flag]:
                count += 1
                flag = 1 - flag
        return count
