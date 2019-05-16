class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        N = len(S)
        result = [0] * (N+1)
        left, right = 0, N
        for i in range(N):
            if S[i] == 'I':
                result[i] = left
                left += 1
            else:
                result[i] = right
                right -= 1
        result[-1] = left
        return result
