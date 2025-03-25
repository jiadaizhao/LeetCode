class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        def countVowel(s):
            count = 0
            for c in s:
                if c in "aeiouAEIOU":
                    count += 1
            return count
        half = len(s) // 2
        return countVowel(s[:half]) == countVowel(s[half:])
