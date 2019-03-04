class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                Q.push({i, 0});
            }
            if (n > 1 && board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                Q.push({i, n - 1});
            }
        }
        
        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                Q.push({0, j});
            }
            
            if (m > 1 && board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                Q.push({m - 1, j});
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for (int k = 0; k < dx.size(); ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                    board[nx][ny] = '#';
                    Q.push({nx, ny});
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
