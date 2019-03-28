class Solution:
    def compress(self, chars: List[str]) -> int:
        count = start = 0
        for i in range(len(chars)):
            if i == len(chars) - 1 or chars[i] != chars[i + 1]:
                chars[count] = chars[i]
                count += 1
                if i > start:
                    for c in str(i - start + 1):
                        chars[count] = c
                        count += 1
                start = i + 1
        return count
