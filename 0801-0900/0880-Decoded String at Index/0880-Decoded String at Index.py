class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        n = 0
        for i, c in enumerate(S):
            if c.isdigit():
                n *= int(c)
            else:
                n += 1
            if n >= K:
                break
        for j in range(i, -1, -1):
            K %= n
            if K == 0 and S[j].isalpha():
                return S[j]
            if S[j].isdigit():
                n //= int(S[j])
            else:
                n -= 1
