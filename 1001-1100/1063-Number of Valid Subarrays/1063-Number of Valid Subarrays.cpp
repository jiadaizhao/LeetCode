class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> St;
        int total = 0;
        for (int num : nums) {
            while (!St.empty() && num < St.top()) {
                St.pop();
            }
            St.push(num);
            total += St.size();
        }
        return total;
    }
};
