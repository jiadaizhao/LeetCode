class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        m, n = len(targetGrid), len(targetGrid[0])
        colors = [[m, n, 0, 0] for _ in range(61)]
        curr = set()
        for i in range(m):
            for j in range(n):
                c = targetGrid[i][j]
                curr.add(c)
                colors[c][0] = min(colors[c][0], i)
                colors[c][1] = min(colors[c][1], j)
                colors[c][2] = max(colors[c][2], i)
                colors[c][3] = max(colors[c][3], j)
                
        def paint(color):
            for i in range(colors[color][0], colors[color][2] + 1):
                for j in range(colors[color][1], colors[color][3] + 1):
                    if targetGrid[i][j] > 0 and targetGrid[i][j] != color:
                        return False
                    
            for i in range(colors[color][0], colors[color][2] + 1):
                for j in range(colors[color][1], colors[color][3] + 1):
                    targetGrid[i][j] = 0
            return True
        
        while curr:
            next = set()
            for color in curr:
                if not paint(color):
                    next.add(color)
            if len(next) == len(curr):
                return False
            curr = next
            
        return True
