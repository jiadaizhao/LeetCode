class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        zero = one = 0
        for c in binary:
            if c == '0':
                zero += 1
            elif zero == 0:
                one += 1
        if zero == 0:
            return binary
        return '1'*(zero + one - 1) + '0' + '1' * (len(binary) - zero - one)
