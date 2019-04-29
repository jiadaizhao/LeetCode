class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        total = i = maxProfit = 0
        for w in sorted(worker):
            while i < len(jobs) and jobs[i][0] <= w:
                maxProfit = max(maxProfit, jobs[i][1])
                i += 1
            total += maxProfit
        return total
