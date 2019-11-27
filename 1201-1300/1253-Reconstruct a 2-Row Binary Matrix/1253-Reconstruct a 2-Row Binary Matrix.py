class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        result = [[0] * len(colsum) for _ in range(2)]
        for j, s in enumerate(colsum):
            if s == 2:
                result[0][j] = result[1][j] = 1
                upper -= 1
                lower -= 1
            elif s == 1:
                if upper >= lower:
                    result[0][j] = 1
                    upper -= 1
                else:
                    result[1][j] = 1
                    lower -= 1
            if upper < 0 or lower < 0:
                return []
        return result if upper == 0 and lower == 0 else []
