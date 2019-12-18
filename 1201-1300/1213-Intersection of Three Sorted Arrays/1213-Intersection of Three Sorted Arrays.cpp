class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        int p1 = 0, p2 = 0, p3 = 0;
        while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()) {
            int currMin = min({arr1[p1], arr2[p2], arr3[p3]});
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) {
                result.push_back(currMin);
            }
            if (arr1[p1] == currMin) ++p1;
            if (arr2[p2] == currMin) ++p2;
            if (arr3[p3] == currMin) ++p3;
        }
        
        return result;
    }
};
