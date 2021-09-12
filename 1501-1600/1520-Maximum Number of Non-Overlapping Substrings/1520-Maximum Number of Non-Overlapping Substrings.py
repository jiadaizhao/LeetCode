class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        start, end = {}, {}
        for i, c in enumerate(s):
            if c not in start:
                start[c] = i
            end[c] = i        
        def checkSubstring(i):
            curr = i
            right = end[s[curr]]
            while curr <= right:
                if start[s[curr]] < i:
                    return -1
                right = max(right, end[s[curr]])
                curr += 1
            return right
        result = []
        prevRight = -1
        for i, c in enumerate(s):
            if i == start[c]:
                right = checkSubstring(i)
                if right != -1:
                    if i > prevRight:
                        result.append(s[i:right + 1])
                    else:
                        result[-1] = s[i:right + 1]
                    prevRight = right
        return result
