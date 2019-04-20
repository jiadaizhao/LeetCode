class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last = {c : i for i, c in enumerate(S)}
        result = []
        start = end = 0
        for i, c in enumerate(S):
            end = max(end, last[c])
            if i == end:
                result.append(i - start + 1)
                start = i + 1
        return result
