class Solution:
    def makeGood(self, s: str) -> str:
        St = []
        for c in s:
            if St and (abs(ord(St[-1]) - ord(c)) == 32):
                St.pop()
            else:
                St.append(c)
        return ''.join(St)
