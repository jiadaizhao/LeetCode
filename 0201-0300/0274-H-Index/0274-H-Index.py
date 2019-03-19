class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        count = [0] * (1 + n)
        for c in citations:
            count[min(c, n)] += 1
        h = n
        num = count[n]
        while num < h:
            h -= 1
            num += count[h]
        return h
