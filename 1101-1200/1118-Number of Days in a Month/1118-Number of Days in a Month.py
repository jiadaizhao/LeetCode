class Solution:
    def numberOfDays(self, Y: int, M: int) -> int:
        table = {1:31, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
        if M != 2:
            return table[M]
        else:
            if Y % 4 == 0 and (Y % 100 or Y % 400 == 0):
                return 29
            else:
                return 28
