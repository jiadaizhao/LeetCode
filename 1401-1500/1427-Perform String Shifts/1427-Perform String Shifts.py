class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        total = sum(amount if direction == 0 else -amount for direction, amount in shift)
        total %= len(s)
        return s[total:] + s[:total]
