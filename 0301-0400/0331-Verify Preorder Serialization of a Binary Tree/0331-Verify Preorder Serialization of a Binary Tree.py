class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        degree = 1
        for s in preorder.split(','):
            degree -= 1
            if degree < 0:
                return False
            if s != '#':
                degree += 2
        return degree == 0
