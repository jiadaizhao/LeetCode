class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A[0].size();
        for (auto& row : A) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = row[j] ^ 1;
                row[j] = row[n - 1 - j] ^ 1;
                row[n - 1 - j] = temp;
            }
        }
        return A;
    }
};
