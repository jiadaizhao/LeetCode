class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        sum = mtc = 0
        for s in satisfaction:
            if sum + s <= 0:
                break
            sum += s
            mtc += sum
        return mtc
