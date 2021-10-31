class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        result = ['a'] * n
        k -= n
        i = n - 1
        while k > 0:
            diff = min(k, 25)
            result[i] = chr(ord('a') + diff)
            i -= 1
            k -= diff
        return ''.join(result)
