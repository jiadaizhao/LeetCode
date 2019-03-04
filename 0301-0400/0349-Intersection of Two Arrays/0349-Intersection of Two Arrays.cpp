class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> table1;
       
        for (int num : nums1) {
            table1.insert(num);
        }
        
        unordered_set<int> table2;
        for (int num : nums2) {
            if(table1.find(num) != table1.end()) {
                table2.insert(num);
            }
        }
        
        return vector<int>(table2.begin(), table2.end());
    }
};
