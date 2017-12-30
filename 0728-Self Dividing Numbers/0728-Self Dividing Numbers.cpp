class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; ++i) {
            int num = i;
            bool valid = true;
            while (num) {
                int temp = num % 10;
                if (temp == 0 || i % temp) {
                    valid = false;
                    break;
                }
                num /= 10;
            }
            if (valid) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
