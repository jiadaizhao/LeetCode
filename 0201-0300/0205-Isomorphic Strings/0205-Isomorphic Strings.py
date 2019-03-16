class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        table = {}
        mapped = set()
        for a, b in zip(s, t):
            if a in table:
                if table[a] != b:
                    return False
            elif b in mapped:
                return False
            table[a] = b
            mapped.add(b)
        return True
