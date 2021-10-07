class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        idx = [[] for _ in range(10)]
        pos = [0] * 10
        for i, ch in enumerate(s):
            idx[int(ch)].append(i)
        for ch in t:
            d = int(ch)
            if pos[d] >= len(idx[d]):
                return False
            for i in range(d):
                if pos[i] < len(idx[i]) and idx[i][pos[i]] < idx[d][pos[d]]:
                    return False
            pos[d] += 1
        return True
