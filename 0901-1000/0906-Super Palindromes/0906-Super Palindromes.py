class Solution:
    def superpalindromesInRange(self, L: str, R: str) -> int:
        L, R = int(L), int(R)
        MAGIC = 100000
        count = 0
        for i in range(MAGIC):
            left = str(i)
            candidate = int(left + left[-2::-1]) ** 2 
            if candidate > R:
                break
            cs = str(candidate)
            if candidate >= L and cs == cs[::-1]:
                count += 1
                
        for i in range(MAGIC):
            left = str(i)
            candidate = int(left + left[::-1]) ** 2
            if candidate > R:
                break
            cs = str(candidate)
            if candidate >= L and cs == cs[::-1]:
                count += 1
        return count
