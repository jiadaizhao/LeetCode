class Solution1:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        result = numBottles
        empty = numBottles
        while empty >= numExchange:
            full, empty = divmod(empty, numExchange)
            result += full
            empty = full + empty
        return result


class Solution2:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        return numBottles + (numBottles - 1) // (numExchange - 1)
