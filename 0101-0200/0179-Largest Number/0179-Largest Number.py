from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def cmp(s1, s2):
            if s1 + s2 > s2 + s1:
                return -1
            elif s1 + s2 < s2 + s1:
                return 1
            else:
                return 0
            
        result = ''.join(sorted(map(str, nums), key=cmp_to_key(cmp)))
        return '0' if result[0] == '0' else result

class Solution2:
    def largestNumber(self, nums: List[int]) -> str:
        class largerNumKey(str):
            def __lt__(x, y):
                return x + y > y + x
            
        result = ''.join(sorted(map(str, nums), key=largerNumKey))
        return '0' if result[0] == '0' else result
