class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        diff = (sum(B) - sum(A)) // 2
        setB = set(B)
        for a in A:
            if a + diff in setB:
                return [a, a + diff]
