class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ha = hour % 12 * 360 / 12 + (double)minutes / 60 * 30;
        double ma = minutes * 360 / 60;
        return min(abs(ha - ma), 360 - abs(ha - ma));
    }
};
