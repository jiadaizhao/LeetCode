import collections
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        table = collections.Counter(A[0])        
        for s in A[1:]:
            table &= collections.Counter(s)
        
        return list(table.elements())
