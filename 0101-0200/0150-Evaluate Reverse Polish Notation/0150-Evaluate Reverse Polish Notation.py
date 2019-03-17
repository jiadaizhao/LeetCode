class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        St = []
        for token in tokens:
            if token.isdigit() or len(token) > 1:
                St.append(int(token))
            else:
                b = St.pop()
                a = St.pop()
                if token == '+':
                    St.append(a + b)
                elif token == '-':
                    St.append(a - b)
                elif token == '*':
                    St.append(a * b)
                else:
                    St.append(int(a / b))
        return St[-1]
