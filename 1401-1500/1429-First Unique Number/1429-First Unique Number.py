import collections
class FirstUnique:

    def __init__(self, nums: List[int]):
        self.table = collections.Counter(nums)
        self.Q = collections.deque(nums)

    def showFirstUnique(self) -> int:
        while self.Q and self.table[self.Q[0]] > 1:
            self.Q.popleft()
        return self.Q[0] if self.Q else -1

    def add(self, value: int) -> None:
        self.Q.append(value)
        self.table[value] += 1


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
