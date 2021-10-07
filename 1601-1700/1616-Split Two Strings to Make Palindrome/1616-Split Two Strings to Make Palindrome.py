class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def isPalindrome(s, left, right):
            while left < right and s[left] == s[right]:
                left += 1
                right -= 1
            return left >= right
        
        def check(a, b):
            left, right = 0, len(a) - 1
            while left < right and a[left] == b[right]:
                left += 1
                right -= 1
            return isPalindrome(a, left, right) or isPalindrome(b, left, right)
        
        return check(a, b) or check(b, a)
