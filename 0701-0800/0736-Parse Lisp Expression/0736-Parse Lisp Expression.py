class Solution:
    def __init__(self):
        self.scope= []

    def evaluate(self, expression: str) -> int:
        def parse(expression):
            bal = 0
            buf = []
            for token in expression.split():
                for c in token:
                    if c == '(':
                        bal += 1
                    elif c == ')':
                        bal -= 1
                buf.append(token)
                if bal == 0:
                    yield ' '.join(buf)
                    buf = []
            if buf:
                yield ' '.join(buf)

        def evaluate_inner(expression):
            if expression[0] != '(':
                if expression[0].isdigit() or expression[0] == '-':
                    return int(expression)
                for local in self.scope[::-1]:
                    if expression in local:
                        return local[expression]
            
            start = 6 if expression[1] == 'm' else 5
            tokens = list(parse(expression[start:-1]))
            if expression.startswith('(add'):
                return self.evaluate(tokens[0]) + self.evaluate(tokens[1])
            elif expression.startswith('(mult'):
                return self.evaluate(tokens[0]) * self.evaluate(tokens[1])
            else:
                for j in range(1, len(tokens), 2):
                    self.scope[-1][tokens[j - 1]] = self.evaluate(tokens[j])
                return self.evaluate(tokens[-1])
        self.scope.append({})    
        result = evaluate_inner(expression)
        self.scope.pop()
        return result
