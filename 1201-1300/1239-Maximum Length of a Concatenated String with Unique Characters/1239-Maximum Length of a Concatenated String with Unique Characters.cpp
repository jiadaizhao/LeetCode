class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLen = 0;
        unordered_set<int> dp;
        for (string s : arr) {
            int curr = 0;
            bool valid = true;
            for (char c : s) {
                int b = 1 << (c - 'a');
                if (curr & b) {
                    valid = false;
                    break;
                }
                curr |= b;
            }

            if (valid) {
                maxLen = max(maxLen, (int)(s.size()));
                dp.insert(curr);
                unordered_set<int> temp = dp;
                for (int x : temp) {
                    if ((curr & x) == 0) {
                        maxLen = max(maxLen, countBits(x) + (int)(s.size()));
                        dp.insert(curr | x);
                    }
                }
            }
        }

        return maxLen;
    }

private:
    int countBits(int num) {
        int count = 0;
        while (num) {
            ++count;
            num &= num - 1;
        }
        return count;
    }
};
