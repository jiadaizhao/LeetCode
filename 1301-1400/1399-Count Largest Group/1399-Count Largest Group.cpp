class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> table;
        for (int i = 1; i <= n; ++i) {
            int sum = 0, temp = i;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            ++table[sum];
        }
        int maxCount = 0, largestSize = 0;
        for (auto p : table) {
            if (p.second > largestSize) {
                largestSize = p.second;
                maxCount = 1;
            }
            else if (p.second == largestSize) {
                ++maxCount;
            }
        }
        return maxCount;
    }
};
