class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxNum = max(candies)
        return [num + extraCandies >= maxNum for num in candies]
