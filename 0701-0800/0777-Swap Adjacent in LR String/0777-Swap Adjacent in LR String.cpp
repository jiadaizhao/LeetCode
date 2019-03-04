class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if ((i < n) ^ (j < n)) return false;
            if (i < n && j < n) {
                if (start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
                    return false;
                }
            }
            ++i;
            ++j;
        }
        
        return true;
    }
};

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int L = 0, R = 0, X = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L') ++L;
            else if (start[i] == 'R') ++R;
            else ++X;

            if (end[i] == 'L') --L;
            else if (end[i] == 'R') --R;
            else --X;
        }
        if (L != 0 || R != 0 || X != 0) return false;

        X = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n) {
                if (start[i] == 'X') {
                    ++X;
                }
                else if (start[i] == 'R') {
                    X = 0;
                }
                else {
                    break;
                }
                ++i;
            }

            while (j < n && end[j] != 'L') ++j;
            if (i - X > j || i < j) return false;
            ++i;
            ++j;
        }
        
        X = 0, i = n - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            while (i >= 0) {
                if (start[i] == 'X') {
                    ++X;
                }
                else if (start[i] == 'L') {
                    X = 0;
                }
                else {
                    break;
                }
                --i;
            }

            while (j >= 0 && end[j] != 'R') --j;
            if (i + X < j || i > j) return false;
            --i;
            --j;
        }
        return true;
    }
};
