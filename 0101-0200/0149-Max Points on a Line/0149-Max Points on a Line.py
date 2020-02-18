import collections
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:        
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        maxNum = 0
        for i in range(len(points)):
            same = localMax = 0
            table = collections.Counter()
            for j in range(i):
                if points[i][0] == points[j][0] and points[i][1] == points[j][1]:
                    same += 1
                else:
                    dx = points[i][0] - points[j][0]
                    dy = points[i][1] - points[j][1]
                    gc = gcd(dx, dy)
                    dx //= gc
                    dy //= gc
                    table[(dx, dy)] += 1
                    localMax = max(localMax, table[(dx, dy)])
            maxNum = max(maxNum, localMax + same + 1)
        return maxNum
