class Solution:
    def lengthLongestPath(self, input: str) -> int:
        lens = [0]
        maxLen = 0
        for line in input.splitlines():
            name = line.lstrip('\t')
            level = len(line) - len(name)
            if '.' in name:
                maxLen = max(maxLen, lens[level] + len(name))
            else:
                if level + 1 == len(lens):
                    lens.append(lens[-1] + 1 + len(name))
                else:
                    lens[level + 1] = lens[level] + 1 + len(name)
        return maxLen
