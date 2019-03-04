class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        int n = data.size();
        while (i < n) {
            if ((data[i] >> 7) == 0) {
                ++i;
            }
            else if ((data[i] >> 5) == 0x6) {
                if (i == n - 1 || (data[i + 1] >> 6) != 0x2) {
                    return false;
                }
                i += 2;
            }
            else if ((data[i] >> 4) == 0xE) {
                if (i >= n - 2 || (data[i + 1] >> 6) != 0x2 || (data[i + 2] >> 6) != 0x2) {
                    return false;
                }
                i += 3;
            }
            else if ((data[i] >> 3) == 0x1E) {
                if (i >= n - 3 || (data[i + 1] >> 6) != 0x2 || (data[i + 2] >> 6) != 0x2 || (data[i + 3] >> 6) != 0x2) {
                    return false;
                }
                i += 4;
            }
            else {
                return false;
            }
        }
        
        return true;
    }
};
