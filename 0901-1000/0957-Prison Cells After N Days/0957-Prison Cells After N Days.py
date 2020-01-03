class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        table = []
        visited = {}
        for i in range(N):
            cells = [0] + [cells[k - 1] ^ cells[k + 1] ^ 1 for k in range(1, 7)] + [0]
            s = str(cells)
            if s in visited:
                j = visited[s]
                index = j + (N - 1 - j) % (i - j)
                return table[index]
            visited[s] = i
            table.append(cells)
        return table[-1]
