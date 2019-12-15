class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2:
            return True
        table = {}
        for s1, s2 in zip(str1, str2):
            if table.setdefault(s1, s2) != s2:
                return False
        return len(set(str2)) < 26
