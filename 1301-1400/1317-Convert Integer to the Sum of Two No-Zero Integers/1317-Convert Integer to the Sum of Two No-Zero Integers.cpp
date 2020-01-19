class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int A = 0;
        bool hasZero = false;
        do {
            ++A;
            hasZero = false;
            if (to_string(A).find('0') != string::npos) {
                hasZero = true;
            }
            else {
                if (to_string(n - A).find('0') != string::npos) {
                    hasZero = true;
                }
            }            
        } while(hasZero);
        return {A, n - A};
    }
};
