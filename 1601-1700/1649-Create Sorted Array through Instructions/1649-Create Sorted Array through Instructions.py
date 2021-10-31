class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        bit = [0] * (max(instructions) + 1)
        def update(i):
            while i < len(bit):
                bit[i] += 1
                i += (-i) & i
                
        def read(i):
            total = 0
            while i > 0:
                total += bit[i]
                i -= (-i) & i
            return total
        MOD = 10 ** 9 + 7
        cost = 0
        for i, val in enumerate(instructions):
            cost = (cost + min(read(val - 1), i - read(val))) % MOD
            update(val)
        return cost
