class Solution:
    def getMaxRepetitions(self, s1: 'str', n1: 'int', s2: 'str', n2: 'int') -> 'int':
        repeatCount = [0]*(1+len(s2))
        nextIndex = [0]*(1+len(s2))
        index = 0
        count = 0
        for k in range(n1):
            for c in s1:
                if c == s2[index]:
                    index += 1
                    if index == len(s2):
                        count += 1
                        index = 0
            repeatCount[k] = count
            nextIndex[k] = index
            for p in range(k):
                if nextIndex[p] == index:
                    prefixCount = repeatCount[p]
                    repeatedPatternCount = (n1 - p - 1) // (k - p) * (repeatCount[k] - repeatCount[p])
                    suffixCount = repeatCount[p + (n1 - p - 1)%(k - p)] - repeatCount[p]
                    return (prefixCount + repeatedPatternCount + suffixCount) // n2
        return count // n2
