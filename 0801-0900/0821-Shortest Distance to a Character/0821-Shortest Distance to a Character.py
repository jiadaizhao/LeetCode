class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        prev = -len(S)
        result = [0] * len(S)
        for i, c in enumerate(S):
            if c == C:
                prev = i
            else:
                result[i] = i - prev
        
        prev = len(S) * 2
        for i in range(len(S) - 1, -1, -1):
            if S[i] == C:
                prev = i
            else:
                result[i] = min(result[i], prev - i)
        return result
