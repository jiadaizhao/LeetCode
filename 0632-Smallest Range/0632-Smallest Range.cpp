class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node> pq;
        int minNum = INT_MAX, maxNum = INT_MIN;
        int k = nums.size();
        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i][0], i, 0);
            minNum = min(minNum, nums[i][0]);
            maxNum = max(maxNum, nums[i][0]);
        }
        
        vector<int> minRange = {minNum, maxNum};
        while (true) {
            Node node = pq.top();
            pq.pop();
            int row = node.row;
            int col = node.col;
            int val = node.val;
            if (maxNum - val < minRange[1] - minRange[0] || (maxNum - val == minRange[1] - minRange[0] && val < minRange[0])) {
                minRange[0] = val;
                minRange[1] = maxNum;
            }
            
            if (col < nums[row].size() - 1) {
                ++col;
                maxNum = max(maxNum, nums[row][col]);
                pq.emplace(nums[row][col], row, col);
            }
            else {
                break;
            }            
        }
     
        return minRange;
    }
    
private:
    struct Node {
        int val;
        int row;
        int col;
        Node (int v, int r, int c): val(v), row(r), col(c) {}
        bool operator < (const Node& node) const {
            return val > node.val; 
        }
    };
};

// Sliding window
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> A;
        int k = nums.size();
        priority_queue<Node> pq;
        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i][0], i, 0);
        }
        
        while (!pq.empty()) {
            int val = pq.top().val;
            int row = pq.top().row;
            int col = pq.top().col;
            pq.pop();
            A.emplace_back(val, row);
            if (col < nums[row].size() - 1) {
                ++col;
                pq.emplace(nums[row][col], row, col);
            }
        }
        
        vector<int> used(k);
        int count = 0;
        vector<int> minRange = {A.front().first, A.back().first};
        int j = 0;
        int n = A.size();
        for (int i = 0; i < n - k + 1; ++i) {
            while (j < n && count != k) {
                if (++used[A[j].second] == 1) {
                    ++count;
                }
                ++j;
            }
                        
            if (count == k) {
                int left = A[i].first;
                int right = A[j - 1].first;
                if (right - left < minRange[1] - minRange[0] ||
                    (right - left == minRange[1] - minRange[0] && left < minRange[0])) {
                    minRange[0] = left;
                    minRange[1] = right;
                }                
            }
                
            if (used[A[i].second]-- == 1) {
                --count;
            }
        }
        
        return minRange;
    }
    
private:
    struct Node {
        int val;
        int row;
        int col;
        Node (int v, int r, int c): val(v), row(r), col(c) {}
        bool operator < (const Node& node) const {
            return val > node.val; 
        }
    };
};
