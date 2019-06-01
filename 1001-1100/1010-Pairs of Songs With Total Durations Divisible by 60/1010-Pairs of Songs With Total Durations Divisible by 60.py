class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        table = [0] * 60
        total = 0
        for t in time:
            t %= 60
            total += table[(60 - t) % 60];
            table[t] += 1
        return total
