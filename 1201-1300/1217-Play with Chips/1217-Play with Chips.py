class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        even = odd = 0
        for i in chips:
            if i & 1:
                odd += 1
            else:
                even += 1
        return min(even, odd)
