class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def isMagic(a,b,c,d,e,f,g,h,i):
            return (sorted([a,b,c,d,e,f,g,h,i]) == list(range(1, 10)) and
                (a+b+c == d+e+f == g+h+i == a+d+g ==
                 b+e+h == c+f+i == a+e+i == c+e+g == 15))
        
        count = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[0]) - 2):
                if grid[i + 1][j + 1] == 5 and isMagic(grid[i][j], grid[i][j+1], grid[i][j+2],
                                                       grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                                                       grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]):
                    count += 1
        return count
