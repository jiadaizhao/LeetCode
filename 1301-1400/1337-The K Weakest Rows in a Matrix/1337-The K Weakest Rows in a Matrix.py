class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        strength = [(sum(row), i) for i, row in enumerate(mat)]
        return [i for _, i in sorted(strength)[:k]]
