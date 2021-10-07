class Solution:
    def thousandSeparator(self, n: int) -> str:
        s = str(n)
        result = []
        for i in range(len(s)):
            if i > 0 and (len(s) - i) % 3 == 0:
                result.append('.')
            result.append(s[i])
        return ''.join(result)
