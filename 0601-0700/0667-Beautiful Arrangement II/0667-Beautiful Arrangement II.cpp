class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);
        int start = 1, end = n;
        int i = 0;
        while (start <= end) {
            if (k > 1) {
                result[i] = (k-- % 2 == 0) ? start++ : end--;
            }
            else {
                result[i] = end--;
            }
            ++i;
        }
        
        return result;
    }
};

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);
        int i = 0;
        while (i < n - k) {
            result[i] = n - i;
            ++i;
        }
        
        int start = 1, end = k;
        bool flag = true;
        while (i < n) {
            result[i++] = flag ? start++ : end--;
            flag = !flag;
        }
        
        return result;
    }
};
