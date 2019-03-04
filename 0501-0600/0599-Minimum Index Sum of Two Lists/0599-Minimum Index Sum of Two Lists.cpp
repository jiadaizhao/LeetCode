class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int m = list1.size(), n = list2.size();
        int maxSum = m + n - 1;
        unordered_map<string, int> table;
        vector<string> result;
        for (int i = 0; i < list1.size(); ++i) {
            table[list1[i]] = i;
        }
        
        for (int j = 0; j < list2.size(); ++j) {
            if (table.find(list2[j]) != table.end()) {
                int i = table[list2[j]];
                if (i + j < maxSum) {
                    maxSum = i + j;
                    result.clear();
                    result.push_back(list2[j]);
                }
                else if (i + j == maxSum) {
                    result.push_back(list2[j]);
                }
            }
        }
        
        return result;
    }
};
