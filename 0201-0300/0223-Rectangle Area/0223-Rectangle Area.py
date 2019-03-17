class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        left = max(A, E)
        right = max(min(C, G), left)
        bottom = max(B, F)
        up = max(min(D, H), bottom)
        return (C - A)*(D - B) + (G - E)*(H - F) - (right - left)*(up - bottom)
