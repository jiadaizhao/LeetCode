import bisect
class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        table = {t : i for i, t in enumerate(target)}
        lis = []
        for a in arr:
            if a not in table:
                continue
            if not lis or table[a] > lis[-1]:
                lis.append(table[a])
            else:
                index = bisect.bisect_left(lis, table[a])
                lis[index] = table[a]
        return len(target) - len(lis)
