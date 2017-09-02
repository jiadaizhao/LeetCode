class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Cell, vector<Cell>, cmp> pq;
        pq.emplace(0, 0, matrix[0][0]);
        int result;
        while (k--)
        {
            Cell cell = pq.top();
            pq.pop();
            result = cell.val;
            int row = cell.row;
            int col = cell.col;
            if (row < n - 1)
            {
                pq.emplace(row + 1, col, matrix[row + 1][col]);
            }
            if (row == 0 && col < n - 1)
            {
                pq.emplace(row, col + 1, matrix[row][col + 1]);
            }
        }
        
        return result;
    }
    
private:
    struct Cell {
        int row;
        int col;
        int val;
        Cell (int r, int c, int v): row(r), col(c), val(v){}
    };
    
    struct cmp {
        bool operator() (Cell& c1, Cell& c2) {
            return c1.val > c2.val;
        }
    };
};

// Range binary search, O(nlog(max - min))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;
            int row = n - 1, col = 0;
            while (row >= 0 && col < n)
            {
                if (matrix[row][col] > mid)
                {
                    --row;
                }
                else
                {
                    ++col;
                    count += row + 1;
                }
            }
            
            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        
        return low;
    }
};
