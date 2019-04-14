class Solution:
    def checkValidString(self, s: str) -> bool:
        low = high = 0
        for c in s:
            low += 1 if c == '(' else -1
            high += 1 if c != ')' else -1
            if high < 0:
                return False
            low = max(low, 0)
        return low == 0
