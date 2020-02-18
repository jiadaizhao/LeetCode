import collections
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        def convert(board):
            return ''.join(str(num) for row in board for num in row)
        curr = convert(board)
        if curr == '123450':
            return 0
        Q = collections.deque([(curr, curr.index('0'))])
        step = 0
        visited = set([curr])
        candidates = {0: [1, 3], 1: [0, 2, 4], 2: [1, 5], 3: [0, 4], 4: [1, 3, 5], 5: [2, 4]}
        while Q:
            step += 1
            for _ in range(len(Q)):
                curr, index = Q.popleft()
                for candidate in candidates[index]:
                    temp = list(curr)
                    temp[index], temp[candidate] = temp[candidate], temp[index]
                    next = ''.join(temp)
                    if next == '123450':
                        return step
                    if next not in visited:
                        Q.append((next, candidate))
                        visited.add(next)
        return -1
