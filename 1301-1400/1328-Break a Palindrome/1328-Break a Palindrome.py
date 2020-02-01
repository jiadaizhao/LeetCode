class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ''
        p = list(palindrome)
        for i in range(len(p) // 2):
            if p[i] != 'a':
                p[i] = 'a'
                break
        else:
            p[-1] = 'b'
        return ''.join(p)
