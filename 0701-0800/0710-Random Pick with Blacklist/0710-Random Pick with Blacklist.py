import random
class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        self.wlen = N - len(blacklist)
        self.table = {b: -1 for b in blacklist}
        mapped = N - 1
        for b in blacklist:
            if b < self.wlen:
                while mapped in self.table:
                    mapped -= 1
                self.table[b] = mapped
                mapped -= 1
                

    def pick(self) -> int:
        index = random.randrange(self.wlen)
        return self.table.get(index, index)


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
