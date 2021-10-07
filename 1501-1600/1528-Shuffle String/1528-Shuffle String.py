class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        table = {i : c for c, i in zip(s, indices)}
        return ''.join([table[i] for i in range(len(s))])
