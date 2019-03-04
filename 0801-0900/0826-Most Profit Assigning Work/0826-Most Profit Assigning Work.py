class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        jobs = list(zip(difficulty, profit))
        jobs.sort()
        total = i = maxProfit = 0
        for w in sorted(worker):
            while i < len(jobs) and jobs[i][0] <= w:
                maxProfit = max(maxProfit, jobs[i][1])
                i += 1
            total += maxProfit
        return total
