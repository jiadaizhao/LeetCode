class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int, int>> Q;
        Q.emplace(x, y);
        board[x][y] = 'B';
        while (!Q.empty()) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            int count = 0;
            for (int i = 0; i < dx.size(); ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                    ++count;
                }
            }
            
            if (count) {
                board[x][y] = '0' + count;
            }
            else {                
                for (int i = 0; i < dx.size(); ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'E') {
                        Q.emplace(nx, ny);
                        board[nx][ny] = 'B';
                    }
                }
            }
        }
        
        return board;
    }
};
