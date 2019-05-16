class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int total = 0;
        for (int a : A) {
            if (a == 1) {
                total += 1;
            }
        }
        if (total == 0) {
            return {0, 2};
        }
        if (total % 3) {
            return {-1, -1};
        }
        int k = total / 3, count = 0, start = 0, mid = 0, end = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 1) {
                ++count;
                if (count == 1) {
                    start = i;
                }
                else if (count == k + 1) {
                    mid = i;
                }
                else if (count == k*2 + 1) {
                    end = i;
                }
            }
        }
        
        while (end < A.size() && A[start] == A[mid] && A[mid] == A[end]) {
            ++start;
            ++mid;
            ++end;
        }
        
        if (end == A.size()) {
            return {start - 1, mid};
        }
        else {
            return {-1, -1};
        }
    }
};
