class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int minSum = 0;
        vector<int> St = {INT_MAX};
        for (int a : arr) {
            while (St.back() <= a) {
                int curr = St.back();
                St.pop_back();
                minSum += curr * min(St.back(), a);
            }
            St.push_back(a);
        }
        
        for (int i = 2; i < St.size(); ++i) {
            minSum += St[i] * St[i - 1];
        }
        return minSum;
    }
};
