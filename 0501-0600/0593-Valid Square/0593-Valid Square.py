class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        def distanceSq(p1, p2):
            return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])
        table = {distanceSq(p1, p2), distanceSq(p1, p3), distanceSq(p1, p4), distanceSq(p2, p3), distanceSq(p2, p4), distanceSq(p3, p4)}
        return 0 not in table and len(table) == 2
