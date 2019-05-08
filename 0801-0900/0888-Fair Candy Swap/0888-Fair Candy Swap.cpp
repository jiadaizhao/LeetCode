class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(B.begin(), B.end(), 0) - accumulate(A.begin(), A.end(), 0)) / 2;
        unordered_set<int> setB(B.begin(), B.end());
        for (int a : A) {
            if (setB.count(a + diff)) {
                return {a, a + diff};
            }
        }
        return {};
    }
};
