// Using stack
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        
        int n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && matrix[i][j] == '1') {
                    heights[i][j] = 1;
                }
                else if (matrix[i][j] == '1') {
                    heights[i][j] = heights[i - 1][j] + 1;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            stack<int> St;
            for (int j = 0; j <= n; ++j) {
                int curr = (j == n) ? 0 : heights[i][j];
                while (!St.empty() && heights[i][St.top()] >= curr) {
                    int h = heights[i][St.top()];
                    St.pop();
                    int w = (St.size()) ? j - St.top() - 1 : j;
                    maxArea = max(maxArea, h * w);
                }
                St.push(j);
            }
        }
        
        return maxArea;
    }
};

// Using DP
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        
        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            int currLeft = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], currLeft);
                    ++height[j];
                }
                else {
                    left[j] = 0;
                    currLeft = j + 1;
                    height[j] = 0;
                }
            }
            
            int currRight = n;
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], currRight);
                    maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
                }
                else {
                    right[j] = n;
                    currRight = j;
                }
            }
        }
        
        return maxArea;
    }
};
