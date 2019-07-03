class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        St = []
        for c in expression:
            if c == ')':
                visited = set()
                while St[-1] != '(':
                    visited.add(St.pop())

                St.pop() # '('
                operator = St.pop()
                if operator == '&':
                    St.append(all(visited))
                elif operator == '|':
                    St.append(any(visited))
                else:
                    St.append(not visited.pop())
            elif c != ',':
                if c == 't':
                    St.append(True)
                elif c == 'f':
                    St.append(False)
                else:
                    St.append(c)

        return St[-1]
        