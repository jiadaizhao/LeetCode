import collections
class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.words = []

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        root = TrieNode()
        for product in products:
            curr = root
            for c in product:                
                curr = curr.next[c]
                curr.words.append(product)
        result = []
        curr = root
        for c in searchWord:
            curr = curr.next[c]
            result.append(sorted(curr.words)[:3])
        
        return result


import bisect
class Solution2:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        result = []
        curr = ''
        i = 0
        for c in searchWord:
            curr += c
            i = bisect.bisect_left(products, curr, i)
            result.append([p for p in products[i:i + 3] if p.startswith(curr)])
        return result
