class Solution:
    def maxLength(self, arr) -> int:
        maxLen = 0
        dp = set()
        for s in arr:
            curr = 0
            valid = True
            for c in s:
                b = ord(c) - ord('a')
                if curr & (1 << b):
                    valid = False
                    break
                curr |= (1 << b)
            if valid:
                maxLen = max(maxLen, len(s))
                dp.add(curr)
                for x in dp.copy():
                    if (curr & x) == 0:
                        maxLen = max(maxLen, bin(x).count('1') + len(s))
                        dp.add(curr | x)

        return maxLen
