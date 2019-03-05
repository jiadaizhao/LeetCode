class Solution:
    def isValid(self, s: str) -> bool:
        St = []
        table = {')':'(', ']':'[', '}':'{'}
        for c in s:
            if c in table:
                if not St or St[-1] != table[c]:
                    return False
                St.pop()
            else:
                St.append(c)
        return not St
