class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        table = [0] * 5
        maxCount = count = 0
        for c in croakOfFrogs:
            index = 'croak'.find(c)
            table[index] += 1
            if index == 0:
                count += 1
                maxCount = max(maxCount, count)
            else:
                table[index - 1] -= 1
                if table[index - 1] < 0:
                    return -1
                if c == 'k':
                    count -= 1
        return maxCount if count == 0 else -1
