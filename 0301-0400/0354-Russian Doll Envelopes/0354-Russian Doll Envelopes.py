import bisect
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        if not envelopes:
            return 0
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        lis = [envelopes[0][1]]
        for w, h in envelopes[1:]:
            if h > lis[-1]:
                lis.append(h)
            else:
                index = bisect.bisect_left(lis, h)
                lis[index] = h
        return len(lis)
