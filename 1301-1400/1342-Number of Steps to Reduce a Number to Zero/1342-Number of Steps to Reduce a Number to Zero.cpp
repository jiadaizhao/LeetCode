class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num != 0) {
            if (num & 1) {
                --num;
            }
            else {
                num >>= 1;
            }
            ++step;
        }
        
        return step;
    }
};
