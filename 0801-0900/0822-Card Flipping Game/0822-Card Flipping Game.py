import itertools
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        same = {x for x, y in zip(fronts, backs) if x == y}
        output = 2001
        for x in itertools.chain(fronts, backs):
            if x not in same:
                output = min(output, x)
        return output % 2001
