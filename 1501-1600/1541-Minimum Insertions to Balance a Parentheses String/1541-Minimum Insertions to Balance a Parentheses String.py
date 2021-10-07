class Solution:
    def minInsertions(self, s: str) -> int:
        right = count = 0
        for c in s:
            if c == '(':
                if right & 1:
                    right -= 1
                    count += 1
                right += 2
            else:
                right -= 1
                if right < 0:
                    right = 1
                    count += 1
        return right + count
