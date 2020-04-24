from functools import reduce
import collections
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
