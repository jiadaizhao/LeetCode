class Solution:
    def maxDepth(self, s: str) -> int:
        bal = depth = 0
        for c in s:
            if c == '(':
                bal += 1
                depth = max(depth, bal)
            elif c == ')':
                bal -= 1
        return depth
