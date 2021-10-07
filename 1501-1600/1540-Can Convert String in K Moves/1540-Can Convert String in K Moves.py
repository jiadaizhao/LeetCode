class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False
        table = [0] * 26
        for a, b in zip(s, t):
            if a != b:
                d = (ord(b) - ord(a)) % 26
                if table[d] * 26 + d > k:
                    return False
                table[d] += 1
        
        return True
