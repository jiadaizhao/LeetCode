import math
import random
class Node:
    __slots__ = 'val', 'levels'
    def __init__(self, val, levels):
        self.val = val
        self.levels = [None] * levels

class Skiplist:
    
    def __init__(self):
        self.maxLevel = 16
        self.head = Node(-1, self.maxLevel)

    def _iter(self, num):
        curr = self.head
        for level in range(self.maxLevel - 1, -1, -1):
            while True:
                future = curr.levels[level]
                if future and future.val < num:
                    curr = future
                else:
                    break
            yield curr, level

    def search(self, target: int) -> bool:
        for prev, level in self._iter(target):
            pass
        curr = prev.levels[0]
        return curr and curr.val == target

    def add(self, num: int) -> None:
        nodelvls = min(self.maxLevel, 1 + int(math.log2(1 / random.random())))
        node = Node(num, nodelvls)
        for curr, level in self._iter(num):
            if level < nodelvls:
                future = curr.levels[level]
                curr.levels[level] = node
                node.levels[level] = future

    def erase(self, num: int) -> bool:
        ans = False
        for curr, level in self._iter(num):
            future = curr.levels[level]
            if future and future.val == num:
                ans = True
                curr.levels[level] = future.levels[level]
        return ans


# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
