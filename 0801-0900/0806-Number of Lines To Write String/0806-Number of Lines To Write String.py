class Solution:
    def numberOfLines(self, widths: List[int], S: str) -> List[int]:
        line = 1
        last = 0
        for c in S:
            w = widths[ord(c) - ord('a')]
            last += w
            if last > 100:
                line += 1
                last = w
        return line, last
