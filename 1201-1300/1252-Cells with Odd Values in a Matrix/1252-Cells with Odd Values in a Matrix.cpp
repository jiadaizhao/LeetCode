class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n), cols(m);
        int countRow = 0, countCol = 0;
        for (auto i : indices) {
            rows[i[0]] ^= 1;
            cols[i[1]] ^= 1;
            countRow += rows[i[0]] ? 1 : -1;
            countCol += cols[i[1]] ? 1 : -1;
        }
        
        return countRow * (m - countCol) + countCol * (n - countRow);
    }
};
