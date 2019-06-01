class Solution:
    def queryString(self, S: str, N: int) -> bool:
        if N > len(S) * 2:
            return False
        return all(bin(i)[2:] in S for i in range(N, N // 2, -1))
