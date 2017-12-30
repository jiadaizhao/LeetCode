class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int num = 0;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) {
                        ++num;
                    }
                }
                count += num * (num - 1) / 2;
            }
        }
        
        return count;
    }
};

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, int> table;
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = j + 1; k < n; ++k) {
                        if (grid[i][k] == 1) {
                            int pos = j * 200 + k;
                            count += table[pos]++;
                        }
                    }
                }                
            }
        }
        
        return count;
    }
};
