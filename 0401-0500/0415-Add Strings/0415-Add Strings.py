class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i = len(num1) - 1
        j = len(num2) - 1
        result = []
        carry = 0
        while i >= 0 or j >= 0 or carry:
            sum = carry
            if i >= 0:
                sum += ord(num1[i]) - ord('0')
                i -= 1
            if j >= 0:
                sum += ord(num2[j]) - ord('0')
                j -= 1
            result.append(str(sum % 10))
            carry = sum // 10
        return ''.join(result[::-1])
