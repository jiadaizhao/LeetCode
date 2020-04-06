class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        result = []
        currA = currB = currC = 0
        while a or b or c:
            if (a >= max(b, c) and currA < 2) or (a > 0 and (currB == 2 or currC == 2)):
                result.append('a')
                a -= 1
                currA += 1
                currB = currC = 0
            elif (b >= max(a, c) and currB < 2) or (b > 0 and (currA == 2 or currC == 2)):
                result.append('b')
                b -= 1
                currB += 1
                currA = currC = 0
            elif (c >= max(a, b) and currC < 2) or (c > 0 and (currA == 2 or currB == 2)):
                result.append('c')
                c -= 1
                currC += 1
                currA = currB = 0
            else:
                break
        return ''.join(result)
