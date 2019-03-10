class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []
        curr = []
        num = 0
        for word in words:
            if len(word) + len(curr) + num > maxWidth:
                for i in range(maxWidth - num):
                    curr[i%(len(curr) - 1 or 1)] += ' '
                result.append(''.join(curr))
                curr = []
                num = 0
            curr.append(word)
            num += len(word)
        return result + [' '.join(curr).ljust(maxWidth)]
