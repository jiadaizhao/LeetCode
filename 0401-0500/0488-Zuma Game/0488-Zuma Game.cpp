class Solution {
public:
    int findMinStep(string board, string hand) {
        int res = INT_MAX;
        vector<int> table(26);
        for (char h : hand) {
            ++table[h - 'A'];
        }
        
        res = helper(board, table);
        return res == INT_MAX ? -1 : res;        
    }
    
private:
    int helper(string board, vector<int>& table) {
        board = removeConsecutive(board);
        if (board.empty()) {
            return 0;
        }
        int cnt = INT_MAX;
        for (int i = 0, j = 0; j <= board.size(); ++j) {
            if (j < board.size() && board[i] == board[j]) {
                continue;
            }
            
            int need = 3 - (j - i);
            if (table[board[i] - 'A'] >= need) {
                table[board[i] - 'A'] -= need;
                int res = helper(board.substr(0, i) + board.substr(j), table);
                if (res != INT_MAX) {
                    cnt = min(cnt, res + need);
                }
                table[board[i] - 'A'] += need;
            }
            
            i = j;
        }
        
        return cnt;
    }
    
    string removeConsecutive(string board) {
        for (int i = 0, j = 0; j <= board.size(); ++j) {
            if (i < board.size() && board[i] == board[j]) {
                continue;
            }
            
            if (j - i >= 3) {
                return removeConsecutive(board.substr(0, i) + board.substr(j));
            }
            
            i = j;
        }
        
        return board;
    }
};
