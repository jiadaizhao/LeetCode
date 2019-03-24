import random
import collections
class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.nums = []
        self.indexTable = collections.defaultdict(list)

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        result = val not in self.indexTable
        self.indexTable[val].append(len(self.nums))
        self.nums.append([val, len(self.indexTable[val]) - 1])
        return result

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.indexTable:
            return False
        index = self.indexTable[val][-1]
        last = self.nums[-1]
        self.indexTable[last[0]][last[1]] = index
        self.nums[index] = last
        self.nums.pop()
        self.indexTable[val].pop()
        if not self.indexTable[val]:
            del self.indexTable[val]
        return True
        
    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return random.choice(self.nums)[0]


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
