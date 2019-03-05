class Solution:
    def romanToInt(self, s: str) -> int:
        romanMap = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        result = 0
        prev = 1000
        for c in s:
            curr = romanMap[c]
            if curr > prev:
                result += curr - prev*2
            else:
                result += curr
            prev = curr
        return result
