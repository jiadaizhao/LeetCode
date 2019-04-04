class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        l = list(s)
        for i in range(0, len(l), k*2):
            l[i:i + k] = reversed(l[i:i + k])
        return ''.join(l)
