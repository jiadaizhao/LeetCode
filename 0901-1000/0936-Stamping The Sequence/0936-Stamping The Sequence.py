class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        m, n = len(stamp), len(target)
        s, t = list(stamp), list(target)
        turn = 0
        res = []
        def overwrite(i):
            change = False
            for j in range(m):
                if t[i + j] == '?':
                    continue
                if s[j] != t[i + j]:
                    return False
                change = True
            if change:
                t[i:i + m] = ['?'] * m
                res.append(i)
            return change

        while turn < 10 * n:
            prev = turn
            for i in range(n - m + 1):
                if overwrite(i):
                    turn += 1
            if t == ['?'] * n:
                return res[::-1]
            if prev == turn:
                break
        return []
