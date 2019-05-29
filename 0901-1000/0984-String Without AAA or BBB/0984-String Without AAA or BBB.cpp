class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result;
        int currA = 0, currB = 0;
        while (A || B) {
            if ((A > B && currA < 2) || B == 0 || currB == 2) {
                result += 'a';
                ++currA;
                --A;
                currB = 0;
            }
            else {
                result += 'b';
                ++currB;
                --B;
                currA = 0;
            }
        }
        
        return result;
    }
};
