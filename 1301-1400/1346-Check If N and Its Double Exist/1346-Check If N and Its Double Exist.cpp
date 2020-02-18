class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> table;
        for (int a : arr) {
            if (table.count(a * 2) || ((a & 1) == 0 && table.count(a / 2))) {
                return true;
            }
            table.insert(a);
        }
        
        return false;
    }
};
