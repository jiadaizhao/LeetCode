class Solution:
    def printVertically(self, s: str) -> List[str]:
        words = s.split()
        maxLen = max(len(word) for word in words)
        result = []
        for i in range(maxLen):
            result.append(''.join(word[i] if i < len(word) else ' ' for word in words))
            result[-1] = result[-1].rstrip()
        return result

import itertools
class Solution2:
    def printVertically(self, s: str) -> List[str]:
        return [''.join(c).rstrip() for c in itertools.zip_longest(*s.split(), fillvalue=' ')]
