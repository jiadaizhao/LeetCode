class Solution {
public:
    bool checkValidString(string s) {
        if (s.size() == 0) {
            return true;
        }
        int sum = 0;
        int count = 0;
        for (char c : s) {
            if (c == '*') {
                ++count;
            }
            else if (c == '(') {
                ++sum;
            }
            else {
                --sum;
                if (sum < 0) {
                    if (count == 0) {
                        return false;
                    }
                    --count;
                    ++sum;
                }
            }
        }
        
        count = sum = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '*') {
                ++count;
            }
            else if (c == ')') {
                ++sum;
            }
            else {
                --sum;
                if (sum < 0) {
                    if (count == 0) {
                        return false;
                    }
                    --count;
                    ++sum;
                }
            }
        }
        
        return true;
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                ++low;
                ++high;
            }
            else if (c == ')') {
                if (low > 0) {
                    --low;
                }
                --high;
            }
            else {
                if (low > 0) {
                    --low;
                }
                ++high;
            }
            
            if (high < 0) {
                return false;
            }
        }
        
        return low == 0;
    }
};
