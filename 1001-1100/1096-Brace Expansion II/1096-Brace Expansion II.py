import itertools
class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        group = [[]]
        bal = 0
        for i, c in enumerate(expression):
            if c == '{':
                if bal == 0:
                    start = i + 1
                bal += 1
            elif c == '}':
                bal -= 1
                if bal == 0:
                    group[-1].append(self.braceExpansionII(expression[start: i]))
            elif bal == 0:
                if c == ',':
                    group.append([])
                else:
                    group[-1].append([c])
        
        word = set()
        for g in group:
            word |= set(map(''.join, itertools.product(*g)))

        return sorted(word)
