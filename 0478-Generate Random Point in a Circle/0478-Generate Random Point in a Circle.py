import math
import random
class Solution:

    def __init__(self, radius, x_center, y_center):
        """
        :type radius: float
        :type x_center: float
        :type y_center: float
        """
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center
        

    def randPoint(self):
        """
        :rtype: List[float]
        """
        r = self.radius * math.sqrt(random.random())
        theta = random.uniform(0, 2 * math.pi)
        return [self.x_center + r * math.cos(theta), self.y_center + r * math.sin(theta)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()