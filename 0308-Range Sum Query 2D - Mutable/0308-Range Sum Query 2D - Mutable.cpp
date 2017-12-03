class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        
        int n = matrix[0].size();
        bit = vector<vector<int>>(1 + m, vector<int>(1 + n));
        matrixCopy = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - matrixCopy[row][col];
        matrixCopy[row][col] = val;
        for (int i = row + 1; i <= matrixCopy.size(); i += (-i) & i) {
            for (int j = col + 1; j <= matrixCopy[i - 1].size(); j += (-j) & j) {
                bit[i][j] += diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return read(row2 + 1, col2 + 1) - read(row1, col2 + 1) - read(row2 + 1, col1) + read(row1, col1);
    }
    
private:
    vector<vector<int>> bit;
    vector<vector<int>> matrixCopy;
    int read(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= (-i) & i) {
            for (int j = y; j > 0; j -= (-j) & j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
 