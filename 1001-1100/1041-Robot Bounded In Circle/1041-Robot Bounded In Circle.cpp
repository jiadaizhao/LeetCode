class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (char c : instructions) {
            if (c == 'L') {
                dir = (dir + 3) % 4;
            }
            else if (c == 'R') {
                dir = (dir + 1) % 4;
            }
            else {
                x += dx[dir];
                y += dy[dir];
            }
        }

        return (x == 0 && y == 0) || dir != 0;
    }
};
