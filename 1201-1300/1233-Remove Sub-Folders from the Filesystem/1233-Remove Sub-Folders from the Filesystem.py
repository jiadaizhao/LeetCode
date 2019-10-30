import collections
class TrieNode:
    def __init__(self):
        self.next = collections.defaultdict(TrieNode)
        self.end = False

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort(key = lambda x : len(x))
        result = []
        root = TrieNode()
        for f in folder:
            curr = root
            subfolder = False
            for i, c in enumerate(f):
                curr = curr.next[c]
                if curr.end and f[i + 1] == '/':
                    subfolder = True
                    break
            
            if not subfolder:
                result.append(f)
                curr.end = True

        return result
