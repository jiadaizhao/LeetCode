import collections
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        i = 0
        def dfs(s):
            nonlocal i
            table = collections.Counter()
            while i < len(s) and s[i] != ')':
                if s[i] == '(':
                    i += 1
                    for k, v in dfs(s).items():
                        table[k] += v
                else:
                    start = i
                    i += 1
                    while i < len(s) and s[i].islower():
                        i += 1
                    name = s[start: i]
                    num = 0
                    while i < len(s) and s[i].isdigit():
                        num = num*10 + int(s[i])
                        i += 1
                    if num == 0:
                        num = 1
                    table[name] += num
            
            if i < len(s):
                # s[i] is ')'
                i += 1
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num*10 + int(s[i])
                    i += 1
                if num != 0:
                    for k in table:
                        table[k] *= num
            return table        
        
        table = dfs(formula)
        return ''.join(k + (str(v) if v > 1 else '') for k, v in sorted(table.items()))

class Solution2:
    def countOfAtoms(self, formula: str) -> str:
        i = 0
        St = [collections.Counter()]
        while i < len(formula):
            if formula[i] == '(':
                i += 1
                St.append(collections.Counter())
            elif formula[i] == ')':
                top = St.pop()
                i += 1
                start = i
                while i < len(formula) and formula[i].isdigit():
                    i += 1
                num = int(formula[start:i] or 1)
                for k, v in top.items():
                    St[-1][k] += v * num
            else:
                start = i
                i += 1
                while i < len(formula) and formula[i].islower():
                    i += 1
                name = formula[start: i]
                start = i
                while i < len(formula) and formula[i].isdigit():
                    i += 1
                num = int(formula[start:i] or 1)
                St[-1][name] += num
                
        return ''.join(k + (str(v) if v > 1 else '') for k, v in sorted(St[-1].items()))
