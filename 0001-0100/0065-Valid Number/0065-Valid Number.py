class Solution:
    def isNumber(self, s: str) -> bool:
        start = 0
        end = len(s) - 1
        while start <= end and s[start] == ' ':
            start += 1
        if start > end:
            return False
        while start <= end and s[end] == ' ':
            end -= 1
        if s[start] == '+' or s[start] == '-':
            start += 1
        num = dot = exp = False
        while start <= end:
            if s[start].isdigit():
                num = True
            elif s[start] == '.':
                if dot or exp:
                    return False
                dot = True
            elif s[start] == 'e':
                if not num or exp:
                    return False
                exp = True
                num = False
            elif s[start] == '+' or s[start] == '-':
                if s[start - 1] != 'e':
                    return False
            else:
                return False
            start += 1
        return num
