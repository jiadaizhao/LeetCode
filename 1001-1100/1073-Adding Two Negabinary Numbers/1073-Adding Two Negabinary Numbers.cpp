class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int i = arr1.size() - 1, j = arr2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int s = carry;
            if (i >= 0) {
                s += arr1[i--];
            }
            if (j >= 0) {
                s += arr2[j--];
            }
            result.push_back(s & 1);
            carry = -(s >> 1);
        }

        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
