from functools import reduce
import collections

class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        root = TrieNode()
        for num in nums:
            node = root
            for i in range(30, -1, -1):
                index = (num >> i) & 1
                node = node.children[index]
        
        result = 0
        for num in nums:
            curr = 0
            node = root
            for i in range(30, -1, -1):
                index = (num >> i) & 1
                if 1 - index in node.children:
                    curr |= (1 << i)
                    node = node.children[1 - index]
                else:
                    node = node.children[index]
            result = max(result, curr)

        return result

class Solution:
    def findMaximumXOR(self, nums: 'List[int]') -> 'int':
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()
        END = True
        for num in nums:
            reduce(dict.__getitem__, '{:031b}'.format(num), trie)[END] = True
            
        result = 0
        candidate = '01'
        for num in nums:
            curr = 0
            node = trie
            for i in range(30, -1, -1):
                mask = 1 << i
                j = 0 if num & mask else 1
                if candidate[j] in node:
                    curr |= mask
                    node = node[candidate[j]]
                else:
                    node = node[candidate[1 - j]]
            result = max(result, curr)
        return result
