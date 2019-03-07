# KMP
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        elif len(haystack) < len(needle):
            return -1
        lps = [0] * len(needle)
        i = 1
        l = 0
        while i < len(needle):
            if needle[i] == needle[l]:
                lps[i] = l + 1
                i += 1
                l += 1
            elif l != 0:
                l = lps[l - 1]
            else:
                i += 1
        
        i = j = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
                if j == len(needle):
                    return i - len(needle)
            elif j != 0:
                j = lps[j - 1]
            else:
                i += 1
        return -1

# Boyer-Moore substring search
class Solution2:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        elif len(haystack) < len(needle):
            return -1
        right = {}
        for i, c in enumerate(needle):
            right[c] = i
        
        i = 0
        while i <= len(haystack) - len(needle):
            skip = 0
            for j in range(len(needle) - 1, -1, -1):
                if needle[j] != haystack[i + j]:
                    skip = j - right.get(haystack[i + j], -1)
                    if skip < 1:
                        skip = 1
                    break
            if skip == 0:
                return i
            i += skip
        return -1