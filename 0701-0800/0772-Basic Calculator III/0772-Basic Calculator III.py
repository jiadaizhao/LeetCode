class Solution:
    def calculate(self, s: str) -> int:
        vals = []
        ops = []
        sign = 1
        def apply(a, b, op):
            if op == '+':
                return a + b
            elif op == '-':
                return a - b
            elif op == '*':
                return a * b
            elif op == '/':
                return a // b
            
        def precedence(op):
            if op == '+' or op == '-':
                return 1
            else:
                return 2
            
        i = 0
        while i < len(s):
            if s[i] == ' ':
                i += 1
                continue
            if s[i].isdigit():
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                vals.append(sign * num)
                sign = 1
            else:
                if s[i] == '(':
                    ops.append(s[i])
                elif s[i] == ')':
                    while ops[-1] != '(':
                        b = vals.pop()
                        a = vals.pop()
                        op = ops.pop()
                        vals.append(apply(a, b, op))
                    ops.pop()
                else:
                    if s[i] == '-' and (i == 0 or s[i - 1] == '('):
                        sign = -1
                    else:
                        while ops and ops[-1] != '(' and precedence(s[i]) <= precedence(ops[-1]):
                            b = vals.pop()
                            a = vals.pop()
                            op = ops.pop()
                            vals.append(apply(a, b, op))
                        ops.append(s[i])
                i += 1
        while ops:
            b = vals.pop()
            a = vals.pop()
            op = ops.pop()
            vals.append(apply(a, b, op))
        
        return vals[-1]
