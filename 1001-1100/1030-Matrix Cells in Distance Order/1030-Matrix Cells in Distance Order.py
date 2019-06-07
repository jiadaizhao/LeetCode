class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        return sorted(([r, c] for r in range(R) for c in range(C)), key=lambda x: abs(x[0] - r0) + abs(x[1] - c0))
