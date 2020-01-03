class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def reverseStr(s, start, end):
            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1
                
        reverseStr(s, 0, len(s) - 1)
        start = 0
        for i, c in enumerate(s):
            if c == ' ':
                reverseStr(s, start, i - 1)
                start = i + 1
        reverseStr(s, start, len(s) - 1)
