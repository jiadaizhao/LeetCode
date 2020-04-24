class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        base = 1 << (n - 1)
        if k > 3 * base:
            return ''
        table = {'a': 'bc', 'b': 'ac', 'c': 'ab'}
        k -= 1
        index, k = divmod(k, base)
        result = chr(ord('a') + index)
        base >>= 1
        while base > 0:
            index, k = divmod(k, base)            
            result += table[result[-1]][index]
            base >>= 1
        return result
