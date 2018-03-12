class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        string s = A + A;
        return s.find(B) != -1;
    }
};
