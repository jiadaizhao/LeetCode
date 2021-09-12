class Solution:
    def reformatDate(self, date: str) -> str:
        day, month, year = date.split()
        monthTable = {"Jan": "01",
                      "Feb": "02",
                      "Mar": "03",
                      "Apr": "04",
                      "May": "05",
                      "Jun": "06",
                      "Jul": "07",
                      "Aug": "08",
                      "Sep": "09",
                      "Oct": "10",
                      "Nov": "11",
                      "Dec": "12"}
        return '-'.join([year, monthTable[month], "{:>02}".format(day[:-2])])
