class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<int> bits(n);
        for (int i = 0; i < m; ++i) {
            bool flip = (A[i][0] == 0);
            for (int j = 0; j < n; ++j) {
                bits[n - 1 - j] += flip ? 1 - A[i][j] : A[i][j];
            }
        }
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (1 << i) * max(bits[i], m - bits[i]);
        }
        return sum;
    }
};

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size(), result = 0;
        for (int j = 0; j < n; ++j) {
            int row = 0;
            for (int i = 0; i < m; ++i) {
                row += (A[i][j] == A[i][0]);
            }
            result += max(row, m - row) * (1 << (n - 1 - j));
        }
        return result;
    }
};
