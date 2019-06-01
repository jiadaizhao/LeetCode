class Solution:
    def isValid(self, S: str) -> bool:
        St = []
        for c in S:
            if c == 'c':
                if St[-2:] != ['a', 'b']:
                    return False
                St.pop()
                St.pop()
            else:
                St.append(c)
        return not St
