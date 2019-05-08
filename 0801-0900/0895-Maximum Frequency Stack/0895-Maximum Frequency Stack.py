import collections
class FreqStack:

    def __init__(self):
        self.freqs = collections.Counter()
        self.freqStacks = collections.defaultdict(list)
        self.maxFreq = 0

    def push(self, x: int) -> None:
        freq = self.freqs[x] + 1
        self.freqs[x] = freq
        self.freqStacks[freq].append(x)
        self.maxFreq = max(self.maxFreq, freq)

    def pop(self) -> int:
        x = self.freqStacks[self.maxFreq].pop()
        self.freqs[x] -= 1
        if len(self.freqStacks[self.maxFreq]) == 0:
            self.maxFreq -= 1
        return x


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()
