class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        total = sum(machines)
        if total % len(machines):
            return -1
        avg = total // len(machines)
        curr = count = 0 
        for m in machines:
            diff = m - avg
            curr += diff
            count = max(count, abs(curr), diff)
        return count
