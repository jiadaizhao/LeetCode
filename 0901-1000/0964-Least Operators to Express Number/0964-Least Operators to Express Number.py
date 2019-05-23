class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        pos = neg = k = 0
        while target:
            target, curr = divmod(target, x)
            if k == 0:                
                pos, neg = curr * 2, (x - curr) * 2
            else:
                pos, neg = min(curr * k + pos, (curr + 1) * k + neg), min((x - curr) * k + pos, (x - curr - 1) * k + neg)
            k += 1
        return min(pos, k + neg) - 1
