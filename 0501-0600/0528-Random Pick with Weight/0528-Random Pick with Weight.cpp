class Solution {
public:
    Solution(vector<int>& w) {
        int total = 0;
        for (int x : w) {
            total += x;
            presum.push_back(total);
        }
    }
    
    int pickIndex() {
        int val = rand() % presum.back() + 1;
        auto it = lower_bound(presum.begin(), presum.end(), val);
        return it - presum.begin();
    }
    
private:
    vector<int> presum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
