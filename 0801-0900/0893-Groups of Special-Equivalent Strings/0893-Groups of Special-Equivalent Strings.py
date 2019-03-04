class Solution:
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        table = set()
        for a in A:
            s = ''.join(sorted(a[0::2])) + ''.join(sorted(a[1::2]))
            table.add(s)
        return len(table)
