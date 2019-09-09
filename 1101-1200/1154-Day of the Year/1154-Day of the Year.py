import datetime
class Solution:
    def dayOfYear(self, date: str) -> int:
        year, month, day = map(int, date.split('-'))
        return (datetime.date(year, month, day) - datetime.date(year, 1, 1)).days + 1
 