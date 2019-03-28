import bisect
class Solution:
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters.sort()
        radius = 0
        for house in houses:
            index = bisect.bisect_left(heaters, house)
            rightRadius = house - heaters[-1] if index == len(heaters) else heaters[index] - house
            leftRadius = house - heaters[index - 1] if index > 0 else rightRadius
            radius = max(radius, min(leftRadius, rightRadius))
        return radius
