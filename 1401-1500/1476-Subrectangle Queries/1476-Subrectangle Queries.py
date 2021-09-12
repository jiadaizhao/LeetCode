class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.rec = rectangle
        self.newRec = []

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        self.newRec.append((row1, col1, row2, col2, newValue))
        

    def getValue(self, row: int, col: int) -> int:
        for i in range(len(self.newRec) - 1, -1, -1):
            if self.newRec[i][0] <= row <= self.newRec[i][2] and self.newRec[i][1] <= col <= self.newRec[i][3]:
                return self.newRec[i][4]
        return self.rec[row][col]


# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)
