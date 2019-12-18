class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        result = []
        start, end = toBeRemoved
        for a, b in intervals:
            if start >= b or end <= a:
                result.append([a, b])
            else:
                if start > a:
                    result.append([a, start])
                if end < b:
                    result.append([end, b])

        return result
