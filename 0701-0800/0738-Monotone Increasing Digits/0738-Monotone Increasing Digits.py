class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        s = list(str(N))
        i = 0
        while i < len(s) - 1:
            if s[i] > s[i + 1]:
                break
            i += 1
        if i == len(s) - 1:
            return N

        for k in range(i, 0, -1):
            if int(s[k - 1]) > int(s[k]) - 1:
                i -= 1
            else:
                break
        s[i] = str(int(s[i]) - 1)
        s[i+1:] = '9'*(len(s) - i - 1)
        return int(''.join(s))
