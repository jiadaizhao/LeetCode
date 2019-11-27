class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        St = []
        bal = 0
        for c in s:
            if c == '(':
                bal += 1
            elif c == ')':
                bal -= 1
            
            if bal >= 0:
                St.append(c)
            else:
                bal = 0
                
        result = []
        for c in reversed(St):
            if c == '(' and bal > 0:
                bal -= 1
            else:
                result.append(c)
        return ''.join(reversed(result))
