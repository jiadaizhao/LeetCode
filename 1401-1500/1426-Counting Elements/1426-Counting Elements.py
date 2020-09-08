class Solution:
    def countElements(self, arr: List[int]) -> int:
        table = set(arr)
        return sum(x + 1 in table for x in arr)
