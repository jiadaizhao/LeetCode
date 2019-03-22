from functools import reduce
class Solution:
    def superPow(self, a: 'int', b: 'List[int]') -> 'int':
        p = reduce(lambda x, y: (10*x + y)%1140, b)
        return pow(a, p, 1337)
