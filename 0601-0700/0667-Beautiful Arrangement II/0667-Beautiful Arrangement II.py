class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        result = [0] * n
        start = 1
        end = n
        i = 0
        while start <= end:
            if k > 1:                
                if k & 1:
                    result[i] = end
                    end -= 1
                else:
                    result[i] = start
                    start += 1
                k -= 1
            else:
                result[i] = end
                end -= 1
            i += 1
        return result
