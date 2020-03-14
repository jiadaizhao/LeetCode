class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        degree = [0] * n
        for left, right in zip(leftChild, rightChild):
            if left != -1:
                degree[left] += 1
                if degree[left] > 1:
                    return False
            if right != -1:
                degree[right] += 1
                if degree[right] > 1:
                    return False
                
        root = -1
        for i, d in enumerate(degree):
            if d == 0:
                if root == -1:
                    root = i
                else:
                    return False
        
        def dfs(curr):
            if curr == -1:
                return 0
            return 1 + dfs(leftChild[curr]) + dfs(rightChild[curr])
        
        return dfs(root) == n
