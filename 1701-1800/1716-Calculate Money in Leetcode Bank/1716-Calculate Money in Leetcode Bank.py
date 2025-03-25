class Solution:
    def totalMoney(self, n: int) -> int:
        week, day = divmod(n, 7)
        return (28 + 28 + 7 * (week - 1)) * week // 2 + (week + 1 + week + day) * day // 2
