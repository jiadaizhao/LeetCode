class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n =grid[0].size();
        vector<int> rows, cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                }
            }
        }
        
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) {
                    cols.push_back(j);
                }
            }
        }
        
        return totalDistance(rows) + totalDistance(cols);
    }
    
private:
    int totalDistance(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int sum = 0;
        while (start < end) {
            sum += nums[end] - nums[start];
            ++start;
            --end;
        }
        
        return sum;
    }
};
