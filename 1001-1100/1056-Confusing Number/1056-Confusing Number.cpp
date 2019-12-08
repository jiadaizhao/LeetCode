class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map<int, int> table;
        table[0] = 0;
        table[1] = 1;
        table[6] = 9;
        table[8] = 8;
        table[9] = 6;
        long num = 0, n = N;
        while (n) {
            int curr = n % 10;
            if (!table.count(curr)) {
                return false;
            }
            num = num * 10 + table[curr];
            n /= 10;
        }

        return num != N;
    }
};
