class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, countL = 0;
        for (char c : s) {
            if (c == 'A') {
                if (++countA > 1) {
                    return false;
                }
                countL = 0;
            }
            else if (c == 'L') {
                if (++countL > 2) {
                    return false;
                }
            }
            else { // 'P'
                countL = 0;
            }
        }
        
        return true;
    }
};
