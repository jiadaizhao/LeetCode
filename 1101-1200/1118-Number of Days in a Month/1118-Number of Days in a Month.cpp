class Solution {
public:
    int numberOfDays(int Y, int M) {
        int table[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (M == 2 && Y % 4 == 0 && (Y % 100 || Y % 400 == 0)) {
            return 29;
        }
        else {
            return table[M];
        }
    }
};
