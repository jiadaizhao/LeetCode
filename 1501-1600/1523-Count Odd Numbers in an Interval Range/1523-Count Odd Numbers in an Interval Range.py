class Solution1:
    def countOdds(self, low: int, high: int) -> int:
        if low & 1:
            return 1 + (high - low) // 2
        else:
            return (high - low + 1) // 2


class Solution2:
    def countOdds(self, low: int, high: int) -> int:
        return (high + 1) // 2 - low // 2
