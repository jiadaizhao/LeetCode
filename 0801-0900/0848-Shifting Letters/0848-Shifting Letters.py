class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        result = []
        s = 0
        for i in range(len(S) - 1, -1, -1):
            s = (s + shifts[i]) % 26
            result.append(chr(ord('a') + (ord(S[i]) - ord('a') + s) % 26))
        return ''.join(result[::-1])
