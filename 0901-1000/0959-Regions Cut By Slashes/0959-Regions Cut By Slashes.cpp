class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        vector<vector<int>> graph(N * 3, vector<int>(N * 3));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '/') {
                    graph[i*3][j*3 + 2] = graph[i*3 + 1][j*3 + 1] = graph[i*3 + 2][j*3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    graph[i*3][j*3] = graph[i*3 + 1][j*3 + 1] = graph[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }
        
        int region = 0;
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph.size(); ++j) {
                if (graph[i][j] == 0) {
                    dfs(graph, i, j);
                    ++region;
                }
            }
        }
        
        return region;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int row, int col) {
        if (row >= 0 && row < graph.size() && col >= 0 && col < graph.size() && graph[row][col] == 0) {
            graph[row][col] = 1;
            dfs(graph, row - 1, col);
            dfs(graph, row + 1, col);
            dfs(graph, row, col - 1);
            dfs(graph, row, col + 1);
        }
    }
};
