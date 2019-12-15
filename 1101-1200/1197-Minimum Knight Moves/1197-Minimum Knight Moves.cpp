class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        x = abs(x);
        y = abs(y);
        if (x > y) swap(x, y);
        if (x == 1 && y == 1) return 2;
        if (x == 2 && y == 2) return 4;
        if (x + y == 1) return 3;
        int m = max((y + 1) / 2, (x + y + 2) / 3);
        return m + (m + x + y) % 2;
    }
};
