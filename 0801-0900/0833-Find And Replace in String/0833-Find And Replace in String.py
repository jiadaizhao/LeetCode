class Solution:
    def findReplaceString(self, S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
        sl = list(S)
        for i, source, target in sorted(zip(indexes, sources, targets), reverse=True):
            if S[i: i + len(source)] == source:
                sl[i: i + len(source)] = target
        return ''.join(sl)
