"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        result = []
        x = 1000
        y = 1
        while x >= 1 and y <= 1000:
            curr = customfunction.f(x, y)
            if curr > z:
                x -= 1
            elif curr < z:
                y += 1
            else:
                result.append([x, y])
                x -= 1
                y += 1
        
        return result
