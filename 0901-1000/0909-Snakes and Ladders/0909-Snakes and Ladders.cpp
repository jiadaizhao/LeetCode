class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, int> steps;
        steps[1] = 0;
        queue<int> Q;
        Q.push(1);
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            for (int k = 1; k <= 6; ++k) {
                int next = curr + k;
                if (next <= n * n) {
                    int rr = (next - 1) / n;
                    int cc = (next - 1) % n;
                    int r = n - 1 - rr;
                    int c = rr % 2 ? n - 1 - cc : cc;
                    if (board[r][c] != -1) {
                        next = board[r][c];
                    }

                    if (next == n * n) {
                        return steps[curr] + 1;
                    }
                    if (!steps.count(next)) {
                        steps[next] = steps[curr] + 1;
                        Q.push(next);
                    }
                }
                else {
                    break;
                }
            }            
        }
        return -1;
    }
};
