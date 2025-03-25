class Trie:
    def __init__(self):
        self.root = {}
        
    def insert(self, num):
        node = self.root
        for i in range(30, -1, -1):
            index = (num >> i) & 1
            if index not in node:
                node[index] = {}
            node = node[index]
        
    def query(self, num):
        if not self.root:
            return -1
        result = 0
        node = self.root
        for i in range(30, -1, -1):
            index = (num >> i) & 1
            if 1 - index in node:
                result |= (1 << i)
                node = node[1 - index]
            else:
                node = node[index]

        return result

class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        nums.sort()
        queries = sorted(enumerate(queries), key=lambda x: x[1][1])
        trie = Trie()
        result = [-1] * len(queries)
        j = 0
        for i, (x, m) in queries:
            while j < len(nums) and nums[j] <= m:
                trie.insert(nums[j])
                j += 1
            result[i] = trie.query(x)
        return result
