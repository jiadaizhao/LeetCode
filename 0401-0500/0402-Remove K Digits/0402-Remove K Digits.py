class Solution:
    def removeKdigits(self, num: 'str', k: 'int') -> 'str':
        St = []
        for c in num:
            while St and c < St[-1] and k > 0:
                St.pop()
                k -= 1
            St.append(c)

        return  ''.join(St[:len(St) - k]).lstrip('0') or '0'
