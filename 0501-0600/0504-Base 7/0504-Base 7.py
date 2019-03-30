class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return '0'
        if num < 0:
            sign = '-'
            num = -num
        else:
            sign = ''
        result = []
        while num > 0:
            result.append(str(num%7))
            num //= 7
        return sign + ''.join(result[::-1])
