class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        ha = hour % 12 * 360 / 12 + minutes / 60 * 30
        ma = minutes * 360 / 60
        return min(abs(ha - ma), 360 - abs(ha - ma))
