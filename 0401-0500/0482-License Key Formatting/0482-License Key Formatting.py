class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        result = []
        for c in reversed(S):
            if c != '-':
                if len(result) % (K + 1) == K:
                    result.append('-')
                result.append(c.upper())
        return ''.join(reversed(result))
