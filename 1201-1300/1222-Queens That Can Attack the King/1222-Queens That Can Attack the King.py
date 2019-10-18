class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        row, col = king
        queens = set((r, c) for r, c in queens)
        result = []
        for dr, dc in (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1):
            for step in range(1, 8):
                r = row + dr * step
                c = col + dc * step
                if r < 0 or r >= 8 or c < 0 or c >= 8:
                    break
                if (r, c) in queens:
                    result.append([r, c])
                    break
        
        return result
