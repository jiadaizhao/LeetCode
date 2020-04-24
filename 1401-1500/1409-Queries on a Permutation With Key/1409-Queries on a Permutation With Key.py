class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        bit = [0] * (m * 2 + 1)
        table = {}
        def read(i):
            total = 0
            while i > 0:
                total += bit[i]
                i -= i & (-i)
            return total

        def update(i, val):
            while i < len(bit):
                bit[i] += val
                i += i & (-i)
        
        for i in range(1, m + 1):
            update(m + i, 1)
            table[i] = m + i

        result = []
        curr = m
        for q in queries:
            result.append(read(table[q]) - 1)
            update(table[q], -1)
            update(curr, 1)
            table[q] = curr
            curr -= 1
        
        return result
