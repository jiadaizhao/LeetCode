class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: (x[1], -x[0]))
        largest = second = -1
        count = 0
        for a, b in intervals:
            is_largest_in = (a <= largest)
            is_second_in = (a <= second)
            if is_largest_in and is_second_in:
                continue
            if is_largest_in:
                count += 1
                second = largest
            else:
                count += 2
                second = b - 1
            largest = b
        return count
