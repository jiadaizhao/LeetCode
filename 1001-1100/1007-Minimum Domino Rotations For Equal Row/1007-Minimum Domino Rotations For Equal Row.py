class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        for candidate in (A[0], B[0]):
            da = db = 0
            for a, b in zip(A, B):
                if a == candidate:
                    if b != candidate:
                        db += 1
                elif b == candidate:
                    da += 1
                else:
                    break
            else:
                return min(da, db)
        return -1
