import collections
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        steps = collections.defaultdict(set)
        steps[0].add(0)
        for stone in stones:
            for step in steps[stone]:
                if step > 1:
                    steps[stone + step - 1].add(step - 1)
                steps[stone + step].add(step)
                steps[stone + step + 1].add(step + 1)
        return len(steps[stones[-1]]) > 0
