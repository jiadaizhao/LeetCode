class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        b5 = b10 = 0
        for bill in bills:
            if bill == 5:
                b5 += 1
            elif bill == 10:
                b10 += 1
                b5 -= 1
            elif b10 > 0:
                b10 -= 1
                b5 -= 1
            else:
                b5 -= 3
            if b5 < 0:
                return False
        return True
