class Solution {
public:
    bool isArmstrong(int N) {
        vector<int> digit;
        int num = N;
        while (num) {
            digit.push_back(num % 10);
            num /= 10;
        }
        int sum = 0;
        for (int d : digit) {
            sum += pow(d, digit.size());
        }
        return sum == N;
    }
};
