class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.size() == 0 || nums2.size() == 0 || k <= 0)
        {
            return result;
        }
        
        priority_queue<Cell, vector<Cell>, cmp> pq;
        pq.emplace(0, 0, nums1[0] + nums2[0]);
        while (!pq.empty() && k--)
        {
            Cell cell = pq.top();
            pq.pop();
            result.emplace_back(nums1[cell.col1], nums2[cell.col2]);
            if (cell.col1 + 1 < nums1.size())
            {
                pq.emplace(cell.col1 + 1, cell.col2, nums1[cell.col1 + 1] + nums2[cell.col2]);
            }
            
            if (cell.col1 == 0 && cell.col2 + 1 < nums2.size())
            {
                pq.emplace(cell.col1, cell.col2 + 1, nums1[cell.col1] + nums2[cell.col2 + 1]);
            }
        }
        
        return result;
    }
    
private:
    struct Cell {
        int col1;
        int col2;
        int val;
        Cell (int c1, int c2, int v): col1(c1), col2(c2), val(v){}
    };
    
    struct cmp {
        bool operator() (Cell c1, Cell c2) {
            return c1.val > c2.val;
        }
    };
};
