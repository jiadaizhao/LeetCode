class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = []
        i = len(a) - 1
        j = len(b) - 1
        s = c = 0
        while i >= 0 or j >= 0 or c:
            s = c
            if i >= 0:
                s += int(a[i])
                i -= 1
            if j >= 0:
                s += int(b[j])
                j -= 1
            c = s // 2
            s %= 2
            result.append(str(s))
        return ''.join(result[::-1])
