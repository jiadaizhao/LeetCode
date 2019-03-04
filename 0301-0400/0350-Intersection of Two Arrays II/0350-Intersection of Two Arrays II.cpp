class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table1;
       
        for (int num : nums1) {
            ++table1[num];
        }
        
        vector<int> result;
        for (int num : nums2) {
            if(table1[num]-- > 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};
