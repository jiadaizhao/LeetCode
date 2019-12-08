class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        table = []
        visited = {}
        for i in range(N):
            cells = [0] + [cells[i - 1] ^ cells[i + 1] ^ 1 for i in range(1, 7)] + [0]
            if str(cells) in visited:
                j = visited[str(cells)]
                index = j + (N - 1 - j) % (i - j)
                return table[index]
            visited[str(cells)] = i
            table.append(cells)
        return table[-1]
