import collections
class Solution:
    def shortestSubarray(self, A: List[int], K: int) -> int:
        presum = [0] * (1 + len(A))
        for i in range(1, len(presum)):
            presum[i] = presum[i - 1] + A[i - 1]
        dq = collections.deque()
        minLen = len(presum)
        for i in range(len(presum)):
            while dq and presum[i] - presum[dq[0]] >= K:
                minLen = min(minLen, i - dq.popleft())
            
            while dq and presum[i] <= presum[dq[-1]]:
                dq.pop()
            dq.append(i)
        return minLen if minLen <= len(A) else -1
