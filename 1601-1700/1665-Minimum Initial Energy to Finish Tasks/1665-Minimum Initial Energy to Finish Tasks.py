class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[0] - x[1])
        result = saved = 0
        for actual, minimum in tasks:
            if saved < minimum:
                result += minimum - saved
                saved = minimum - actual
            else:
                saved -= actual
        return result
