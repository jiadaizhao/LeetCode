class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        maxLen = bal = 0
        table = {}
        for i, h in enumerate(hours):
            if hours[i] > 8:
                bal += 1
            else:
                bal -= 1

            table.setdefault(bal, i)
            if bal > 0:
                maxLen = i + 1
            else:                
                if bal - 1 in table:
                    maxLen = max(maxLen, i - table[bal - 1])

        return maxLen
