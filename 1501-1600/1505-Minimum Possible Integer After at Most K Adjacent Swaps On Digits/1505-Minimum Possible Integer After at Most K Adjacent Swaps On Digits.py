class BinaryIndexTree:
    def __init__(self, n):
        self.nums = [0] * (1+ n)
    def update(self, i, delta):
        while i < len(self.nums):
            self.nums[i] += delta
            i += (i & -i)
    def query(self, i):
        result = 0
        while i > 0:
            result += self.nums[i]
            i -= (i & -i)
        return result

class Solution:
    def minInteger(self, num: str, k: int) -> str:
        n = len(num)
        pos = [[] for _ in range(10)]
        for i in range(n-1, -1, -1):
            pos[ord(num[i]) - ord('0')].append(i)

        def find_best():
            for d in range(10):
                if not pos[d]:
                    continue
                i = pos[d][-1]
                cost = i - tree.query(i)
                if cost <= k: return d, cost
            return None, None

        tree = BinaryIndexTree(n)
        res = []
        removed = [False] * n
        
        while k:
            d, cost = find_best()
            if d is None:
                break
            k -= cost
            res.append(d)
            i = pos[d].pop()
            tree.update(i+1, 1)
            removed[i] = True
            
        lhs = ''.join(str(d) for d in res)
        rhs = ''.join(num[i] for i in range(n) if not removed[i])
        return lhs + rhs
