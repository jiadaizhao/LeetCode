class Solution:
    def freqAlphabets(self, s: str) -> str:
        result = []
        i = 0
        table = {str(i) : chr(ord('a') + i - 1) for i in range(1, 11)}
        table.update({str(i) + '#' : chr(ord('j') + i - 10) for i in range(10, 27)})
        while i < len(s):
            if i + 2 < len(s) and s[i + 2] == '#':
                result.append(table[s[i:i + 3]])
                i += 3
            else:
                result.append(table[s[i]])
                i += 1

        return ''.join(result)
