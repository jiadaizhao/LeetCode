class Solution:
    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        count = R * C - 1
        step = 1
        result = [[r0, c0]]
        r, c = r0, c0
        while count:
            for j in range(step):
                nr, nc = r, c + j + 1
                if 0 <= nr < R and 0 <= nc < C:
                    result.append([nr, nc])
                    count -= 1
            c += step

            for i in range(step):
                nr, nc = r + i + 1, c
                if 0 <= nr < R and 0 <= nc < C:
                    result.append([nr, nc])
                    count -= 1
            r += step
                    
            step += 1
            for j in range(step):
                nr, nc = r, c - j - 1
                if 0 <= nr < R and 0 <= nc < C:
                    result.append([nr, nc])
                    count -= 1
            c -= step

            for i in range(step):
                nr, nc = r - i - 1, c
                if 0 <= nr < R and 0 <= nc < C:
                    result.append([nr, nc])
                    count -= 1
            r -= step
            step += 1
        return result
