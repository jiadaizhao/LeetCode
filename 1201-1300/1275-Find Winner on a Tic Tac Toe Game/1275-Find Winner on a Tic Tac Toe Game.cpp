class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3), cols(3);
        int diag = 0, antidiag = 0;
        for (int i = 0; i < moves.size(); ++i) {
            int val = (i & 1) ? 1 : -1;
            int r = moves[i][0], c = moves[i][1];
            rows[r] += val;
            cols[c] += val;
            if (r == c) diag += val;
            if (r + c == 2) antidiag += val;
            if (abs(rows[r]) == 3 || abs(cols[c]) == 3 || abs(diag) == 3 || abs(antidiag) == 3)
                return (i & 1) ? "B" : "A";
        }
        
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
