class Solution:
    def parseTernary(self, expression: str) -> str:
        St = []
        for i in range(len(expression) - 1, -1, -1):
            c = expression[i]
            if St and St[-1] == '?':
                St.pop()
                left = St.pop()
                right = St.pop()
                if c == 'T':
                    St.append(left)
                else:
                    St.append(right)
            elif c != ':':
                St.append(c)
        return St[0]
