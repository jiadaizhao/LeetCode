class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        result = []
        bal = 0
        for c in S:
            if c == '(':
                bal += 1
                if bal > 1:
                    result.append(c)
            else:
                bal -= 1
                if bal > 0:
                    result.append(c)
        return ''.join(result)
