class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        curr = 0
        result = [False] * len(A)
        for i, a in enumerate(A):
            curr = (curr * 2 + a) % 5
            if curr == 0:
                result[i] = True
        return result
