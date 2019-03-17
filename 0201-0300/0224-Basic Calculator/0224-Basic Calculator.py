class Solution:
    def calculate(self, s: str) -> int:
        St = []
        result = num = i = 0
        sign = 1
        while i < len(s):
            if s[i].isdigit():
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + ord(s[i]) - ord('0')
                    i += 1
                result += sign * num
                num = 0
            else:
                if s[i] == '+':
                    sign = 1
                elif s[i] == '-':
                    sign = -1
                elif s[i] == '(':
                    St.append(sign)
                    St.append(result)
                    sign = 1
                    result = 0
                elif s[i] == ')':
                    result = St.pop() + St.pop() * result
                i += 1
        return result
