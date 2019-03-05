class Solution:
    def myAtoi(self, str: str) -> int:
        i = 0
        while i < len(str) and str[i] == ' ':
            i += 1
        if i == len(str):
            return 0
        sign = 1
        if str[i] == '+':
            i += 1
        elif str[i] == '-':
            sign = -1
            i += 1
        
        result = 0
        INT_MAX = (1 << 31) - 1
        INT_MIN = -(1 << 31)
        while i < len(str):
            if not str[i].isdigit():
                break
            result = result * 10 + ord(str[i]) - ord('0')
            if result > INT_MAX:
                return INT_MAX if sign > 0 else INT_MIN
            i += 1
        return sign*result
