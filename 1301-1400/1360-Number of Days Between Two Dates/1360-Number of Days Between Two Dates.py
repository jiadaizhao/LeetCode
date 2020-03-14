from datetime import date
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        d1 = date(*map(int, date1.split('-')))
        d2 = date(*map(int, date2.split('-')))
        return abs((d1 - d2).days)
