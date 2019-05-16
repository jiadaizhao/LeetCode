class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        result = list(S)
        start = 0
        end = len(S) - 1
        while start < end:
            while start < end and not result[start].isalpha():
                start += 1
            while start < end and not result[end].isalpha():
                end -= 1
            if start < end:
                result[start], result[end] = result[end], result[start]
                start += 1
                end -= 1
        return ''.join(result)
