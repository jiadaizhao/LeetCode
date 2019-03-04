class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> visited;
        string curr = convert(board);
        visited.insert(curr);
        queue<vector<vector<int>>> Q;
        vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
        Q.push(board);
        int step = -1;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!Q.empty()) {
            ++step;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                auto b = Q.front();
                Q.pop();
                
                if (b == target) return step;
                int x, y;
                for (int i = 0; i < 2; ++i)
                    for (int j = 0; j < 3; ++j)
                        if (b[i][j] == 0) {
                            x = i;
                            y = j;
                            break;
                        }
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
                        swap(b[x][y], b[nx][ny]);
                        string s = convert(b);
                        if (!visited.count(s)) {
                            Q.push(b);
                            visited.insert(s);
                        }
                        swap(b[x][y], b[nx][ny]);
                    }
                }                
            }
        }
        return -1;
    }
    
private:
    string convert(vector<vector<int>>& board) {
        string str;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                str += '0' + board[i][j];
        return str;
    }
};
