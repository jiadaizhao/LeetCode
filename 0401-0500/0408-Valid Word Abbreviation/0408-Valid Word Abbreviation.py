class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        i = num = 0
        for c in abbr:
            if c.isdigit():
                num = num * 10 + ord(c) - ord('0')
                if num == 0:
                    return False
            else:
                i += num
                if i >= len(word) or word[i] != c:
                    return False
                num = 0
                i += 1
        
        i += num
        return i == len(word)
