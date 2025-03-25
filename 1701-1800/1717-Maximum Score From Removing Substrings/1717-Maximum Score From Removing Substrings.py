class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x >= y:
            first, second = 'a', 'b'
        else:
            first, second = 'b', 'a'
            x, y = y, x
        
        St = []
        result = 0
        for c in s:
            if c == second and St and St[-1] == first:
                result += x
                St.pop()
            else:
                St.append(c)
        
        St2 = []
        for c in St:
            if c == first and St2 and St2[-1] == second:
                result += y
                St2.pop()
            else:
                St2.append(c)
        return result
