class Solution:
    def reformat(self, s: str) -> str:
        a = [c for c in s if c.isalpha()]
        d = [c for c in s if c.isdigit()]
        if len(d) > len(a) + 1 or len(a) > len(d) + 1:
            return ''
        if len(a) <= len(d):
            a, d = d, a
        result = []
        for i in range(len(a) + len(d)):
            if i & 1:
                result.append(d[i // 2])
            else:
                result.append(a[i // 2])
        
        return ''.join(result)
