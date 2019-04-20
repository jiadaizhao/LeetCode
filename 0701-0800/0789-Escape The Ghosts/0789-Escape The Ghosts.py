class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        dist = abs(target[0]) + abs(target[1])
        for ghost in ghosts:
            if abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= dist:
                return False
        return True

class Solution2:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        return all(abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) > abs(target[0]) + abs(target[1]) for ghost in ghosts)
