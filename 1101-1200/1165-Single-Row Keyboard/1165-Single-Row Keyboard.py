class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        table = {c: i for i, c in enumerate(keyboard)}
        time = prev = 0
        for c in word:
            time += abs(table[c] - prev)
            prev = table[c]
        return time
