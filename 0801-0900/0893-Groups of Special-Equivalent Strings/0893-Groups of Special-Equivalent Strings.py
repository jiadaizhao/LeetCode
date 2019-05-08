class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        return len(set(''.join(sorted(a[0::2])) + ''.join(sorted(a[1::2])) for a in A))
