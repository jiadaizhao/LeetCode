class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total = curr = start = 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            curr += gas[i] - cost[i]
            if curr < 0:
                curr = 0
                start = i + 1
        return start if total >= 0 else -1
