class Solution:
    def toHexspeak(self, num: str) -> str:
        s = hex(int(num)).upper()[2:]
        result = ''
        for c in s:
            if '1' < c <= '9':
                return 'ERROR'
            if c == '0':
                result += 'O'
            elif c == '1':
                result += 'I'
            else:
                result += c
        return result
