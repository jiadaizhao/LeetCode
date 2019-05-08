class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        step = sign = 1
        result = [[r0, c0]]
        r, c = r0, c0
        while len(result) < R*C:
            for _ in range(step):
                c += sign
                if 0 <= r < R and 0 <= c < C:
                    result.append([r, c])

            for _ in range(step):
                r += sign
                if 0 <= r < R and 0 <= c < C:
                    result.append([r, c])
                    
            step += 1
            sign *= -1
        return result
