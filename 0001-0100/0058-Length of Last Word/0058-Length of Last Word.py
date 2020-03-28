class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        end = len(s) - 1
        while end >= 0 and s[end] == ' ':
            end -= 1
        count = 0
        while end >= 0 and s[end] != ' ':
            end -= 1
            count += 1
        return count
