class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> table(1001);
        for (int a : arr1) {
            ++table[a];
        }

        vector<int> result(arr1.size());
        int i = 0;
        for (int a : arr2) {
            while (table[a] > 0) {
                result[i++] = a;
                --table[a];
            }
        }

        for (int j = 0; j < table.size(); ++j) {
            while (table[j] > 0) {
                result[i++] = j;
                --table[j];
            }
        }

        return result;
    }
};
