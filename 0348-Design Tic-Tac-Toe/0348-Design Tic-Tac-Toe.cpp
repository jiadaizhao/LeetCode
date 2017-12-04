class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n);
        cols.resize(n);
        diag = 0;
        antidiag = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int val = (player == 1) ? 1 : -1;
        int n = rows.size();
        rows[row] += val;
        cols[col] += val;
        if (row == col) {
            diag += val;
        }
        
        if (row + col == n - 1) {
            antidiag += val;
        }
        
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(antidiag) == n) {
            return player;
        }
        else {
            return 0;
        }        
    }
    
private:
    vector<int> rows;
    vector<int> cols;
    int diag, antidiag;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
 