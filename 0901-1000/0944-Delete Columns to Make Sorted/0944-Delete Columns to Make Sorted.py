class Solution:
    def minDeletionSize(self, A: 'List[str]') -> 'int':
        return sum(any(s[i] > s[i + 1] for i in range(len(s) - 1)) for s in zip(*A))
