class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        self.table = [[-1] * n for _ in range(16)]
        for i in range(n):
            self.table[0][i] = parent[i]
        for i in range(16):
            for node in range(n):
                p = self.table[i - 1][node]
                if p != -1:
                    self.table[i][node] = self.table[i - 1][p]

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(16):
            if k & (1 << i):
                node = self.table[i][node]
                if node == -1:
                    return -1
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
