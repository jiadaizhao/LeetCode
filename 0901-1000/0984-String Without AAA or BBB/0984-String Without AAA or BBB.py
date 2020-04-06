class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        result = []
        currA = currB = 0
        while A or B:
            if (A > B and currA < 2) or currB == 2:
                result.append('a')
                A -= 1
                currA += 1
                currB = 0
            else:
                result.append('b')
                B -= 1
                currB += 1
                currA = 0
        return ''.join(result)
