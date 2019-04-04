class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.isupper() or word.islower() or word.istitle()

class Solution2:
    def detectCapitalUse(self, word: str) -> bool:
        allUpper = False
        allLower = word[0].islower()
        for c in word[1:]:
            if c.islower():
                if allUpper:
                    return False
                allLower = True
            else:
                if allLower:
                    return False
                allUpper = True
        return True
