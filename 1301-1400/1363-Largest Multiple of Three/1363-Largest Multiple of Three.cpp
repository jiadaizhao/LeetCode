class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {        
        vector<int> count(10);
        for (int d : digits) {
            ++count[d];
        }
        int remain1Count = count[1] + count[4] + count[7];
        int remain2Count = count[2] + count[5] + count[8];
        int total = accumulate(digits.begin(), digits.end(), 0);
        if (total % 3 == 1) {
            if (remain1Count > 0) {
                --remain1Count;
            }
            else {
                remain2Count -= 2;
            }
        }
        else if (total % 3 == 2) {
            if (remain2Count > 0) {
                --remain2Count;
            }
            else {
                remain1Count -= 2;
            }
        }
        string result;
        for (int d = 9; d >= 0; --d) {
            int num = count[d];
            if (d % 3 == 1) {
                num = min(num, remain1Count);
                remain1Count -= num;
            }
            else if (d % 3 == 2) {
                num = min(num, remain2Count);
                remain2Count -= num;
            }
            result += string(num, '0' + d);
        }
        return result.size() && result[0] == '0' ? "0" : result;
    }
};
