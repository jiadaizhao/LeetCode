class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        A = B = 0
        result = [0] * len(seq)
        for i, c in enumerate(seq):
            if c == '(':
                if A < B:
                    A += 1
                else:
                    B += 1
                    result[i] = 1
            else:
                if A > B:
                    A -= 1
                else:
                    B -= 1
                    result[i] = 1
        return result
