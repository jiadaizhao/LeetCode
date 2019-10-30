class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        difx1 = coordinates[1][0] - coordinates[0][0]
        dify1 = coordinates[1][1] - coordinates[0][1]
        for i in range(2, len(coordinates)):
            difx2 = coordinates[i][0] - coordinates[0][0]
            dify2 = coordinates[i][1] - coordinates[0][1]
            if difx2 * dify1 != difx1 * dify2:
                return False
        return True
