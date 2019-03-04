class Solution:
    def subarrayBitwiseORs(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        curr = set()
        total = set()
        for a in A:
            curr = {a | x for x in curr} | {a}
            total |= curr
        return len(total)
