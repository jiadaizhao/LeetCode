class Solution:
    def balancedStringSplit(self, s: str) -> int:
        bal = num = 0
        for c in s:
            if c == 'L':
                bal += 1
            else:
                bal -= 1
            if bal == 0:
                num += 1
        
        return num
