import math
class Solution:
    def canMeasureWater(self, x: 'int', y: 'int', z: 'int') -> 'bool':
        if x + y < z:
            return False
        if x == 0 and y == 0:
            return z == 0
        return z % math.gcd(x, y) == 0
