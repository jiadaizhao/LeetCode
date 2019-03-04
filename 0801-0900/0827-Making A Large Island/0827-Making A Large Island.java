class Solution {
    public int largestIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] parents = new int[m * n], areas = new int[m * n];
        for (int i = 0; i < m * n; ++i) {
            parents[i] = i;
        }

        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int p1 = i * n + j;
                    areas[p1] = 1;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        p1 = findParent(parents, (i - 1) * n + j);
                        parents[i * n + j] = p1;
                        ++areas[p1];
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        p1 = findParent(parents, i * n + j - 1);
                        int p2 = findParent(parents, i * n + j);
                        if (p1 != p2) {
                            parents[p2] = p1;
                            areas[p1] += areas[p2]; 
                        }                           
                    }
                    maxArea = Math.max(maxArea, areas[p1]);
                }
            }
        }
        
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    areas[i * n + j] = 1;
                    Set<Integer> visited = new HashSet();
                    for (int k = 0; k < 4; ++k) {
                        int r = i + dr[k];
                        int c = j + dc[k];
                        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {                            
                            int p = findParent(parents, r * n + c);
                            if (!visited.contains(p)) {
                                visited.add(p);
                                areas[i * n + j] += areas[p];
                            }                            
                        }                        
                    }
                    maxArea = Math.max(maxArea, areas[i * n + j]);
                }
            }
        }
        return maxArea;
    }
    
    private int findParent(int[] parents, int i) {
        while (parents[i] != i) {
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return i;
    }
}
