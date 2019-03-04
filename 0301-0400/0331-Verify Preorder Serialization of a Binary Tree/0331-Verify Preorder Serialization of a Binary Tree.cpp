class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string s;
        int degree = 1;
        while (getline(ss, s, ',')) {
            --degree;
            if (degree < 0) {
                return false;
            }
            if (s != "#") {
                degree += 2;
            }
        }
        
        return degree == 0;
    }
};
