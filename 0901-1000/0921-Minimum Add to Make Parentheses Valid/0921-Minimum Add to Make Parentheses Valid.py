class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        bal = left = 0
        for c in S:
            bal += 1 if c == '(' else -1
            if bal < 0:
                bal += 1
                left += 1
        return bal + left
