class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        vector<int> counts(26);
        bool duplicate = false;
        int diff = 0, first = -1, second = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != B[i]) {
                ++diff;
                if (diff == 1) {
                    first = i;
                }
                else if (diff == 2) {
                    second = i;
                }
                else {
                    return false;
                }
            }
            else if (++counts[A[i] - 'a'] > 1){
                duplicate = true;
            }
        }
        return (diff == 0 && duplicate == true) || (diff == 2 && A[first] == B[second] && A[second] == B[first]);
    }
};
