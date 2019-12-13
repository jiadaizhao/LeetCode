class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        point = s = 0
        for i in range(len(calories)):
            s += calories[i]            
            if i >= k - 1:
                if i >= k:
                    s -= calories[i - k]
                if s < lower:
                    point -= 1
                elif s > upper:
                    point += 1
        return point
