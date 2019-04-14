class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        orig = image[sr][sc]
        if orig == newColor:
            return image
        m = len(image)
        n = len(image[0])
        def dfs(r, c):
            if orig == image[r][c]:
                image[r][c] = newColor
                if r > 0:
                    dfs(r - 1, c)
                if r < m - 1:
                    dfs(r + 1, c)
                if c > 0:
                    dfs(r, c - 1)
                if c < n - 1:
                    dfs(r, c + 1)
        dfs(sr, sc)
        return image
