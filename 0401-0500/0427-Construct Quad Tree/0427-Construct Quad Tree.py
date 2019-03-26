# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        if not grid:
            return None
        def construct(row1, col1, row2, col2):
            if row1 == row2 and col1 == col2:
                return Node(bool(grid[row1][col1]), True, None, None, None, None)
            topLeft = construct(row1, col1, (row1 + row2)//2, (col1 + col2)//2)
            topRight = construct(row1, (col1 + col2)//2 + 1, (row1 + row2)//2, col2)
            bottomLeft = construct((row1 + row2)//2 + 1, col1, row2, (col1 + col2)//2)
            bottomRight = construct((row1 + row2)//2 + 1, (col1 + col2)//2 + 1, row2, col2)
            if topLeft.isLeaf and topRight.isLeaf and bottomLeft.isLeaf and bottomRight.isLeaf and \
                topLeft.val == topRight.val == bottomLeft.val == bottomRight.val:
                return Node(topLeft.val, True, None, None, None, None)
            else:
                return Node(True, False, topLeft, topRight, bottomLeft, bottomRight)
            
        return construct(0, 0, len(grid) - 1, len(grid[0]) - 1)
