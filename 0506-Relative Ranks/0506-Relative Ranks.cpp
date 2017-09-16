class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        {
            return vector<string>();
        }
        vector<pair<int, int>> cells(n);
        for (int i = 0; i < n; ++i)
        {
            cells[i] = {i, nums[i]};
        }
        
        sort(cells.begin(), cells.end(), cmp());
        vector<string> result(n);
        for (int i = 0; i < n; ++i)
        {
            string rank;
            if (i == 0)
            {
                rank = "Gold Medal";
            }
            else if (i == 1)
            {
                rank = "Silver Medal";
            }
            else if (i == 2)
            {
                rank = "Bronze Medal";
            }
            else
            {
                rank = to_string(i + 1);
            }
            
            result[cells[i].first] = rank;
        }
        
        return result;
    }
    
private:
    struct cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        }    
    };
};
