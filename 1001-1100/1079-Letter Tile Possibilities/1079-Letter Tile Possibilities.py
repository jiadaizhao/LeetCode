class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        tiles.sort()
        used = [False] * len(tiles)
        def dfs():
            total = 0
            for i in range(len(tiles)):
                if used[i]:
                    continue

                if i > 0 and tiles[i] == tiles[i - 1] and not used[i - 1]:
                    continue

                total += 1
                used[i] = True
                dfs()
                used[i] = False
            return total

        return dfs()
