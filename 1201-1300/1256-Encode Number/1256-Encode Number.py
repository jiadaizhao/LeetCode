class Solution:
    def encode(self, num: int) -> str:
        if num == 0:
            return ''
        base = 0
        while num >= (1 << base):
            num -= (1 << base)
            base += 1
        return format(num, '0' + str(base) + 'b')


class Solution2:
    def encode(self, num: int) -> str:
        return bin(num + 1)[3:]
