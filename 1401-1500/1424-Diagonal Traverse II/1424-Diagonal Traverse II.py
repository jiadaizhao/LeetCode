class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        table = sorted((r + c, -r, val) for r, row in enumerate(nums) for c, val in enumerate(row))
        return [val for _, _, val in table]
