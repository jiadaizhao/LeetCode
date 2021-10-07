class Solution:
    def modifyString(self, s: str) -> str:
        result = []
        n = len(s)
        for i in range(n):
            if s[i] == '?':
                left = result[-1] if i > 0 else 'A'
                right = s[i + 1] if i < n - 1 else 'B'
                for c in 'abc':
                    if c != left and c != right:
                        result.append(c)
                        break
            else:
                result.append(s[i])
        return ''.join(result)
