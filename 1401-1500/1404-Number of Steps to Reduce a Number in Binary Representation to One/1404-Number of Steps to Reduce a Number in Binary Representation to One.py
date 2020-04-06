class Solution:
    def numSteps(self, s: str) -> int:
        zero = 0
        start = i = 1
        while i < len(s):
            if s[i] == '1':
                while i < len(s) and s[i] == '1':
                    i += 1
                start = i
            else:
                while i < len(s) and s[i] == '0':
                    i += 1
                if i != len(s):
                    zero += i - start
        
        if start == 1:
            return len(s) - 1
        return zero + 1 + len(s)
