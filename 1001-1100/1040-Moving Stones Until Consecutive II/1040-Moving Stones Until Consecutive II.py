class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones.sort()
        maxMove = max(stones[-2] - stones[0] - len(stones) + 2, stones[-1] - stones[1] - len(stones) + 2)
        minMove = len(stones)
        start = 0
        for i in range(len(stones)):
            while stones[i] - stones[start] >= len(stones):
                start += 1

            if i - start + 1 == len(stones) - 1 and stones[i] - stones[start] == len(stones) - 2:
                minMove = min(minMove, 2)
            else:
                minMove = min(minMove, len(stones) - (i - start + 1))

        return [minMove, maxMove]
