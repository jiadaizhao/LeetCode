class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size(), turn = 0;
        vector<int> result;
        while (turn < 10 * n) {
            int prev = turn;
            for (int i = 0; i < n - m + 1; ++i) {
                if (overwrite(stamp, target, i, result)) {
                    ++turn;
                }
            }
            if (target == string(n, '?')) {
                reverse(result.begin(), result.end());
                return result;
            }
            if (prev == turn) {
                break;
            }
        }
        return {};
    }
    
private:
    bool overwrite(string& stamp, string& target, int i, vector<int>& result) {
        bool change = false;
        for (int j = 0; j < stamp.size(); ++j) {
            if (target[i + j] == '?') {
                continue;
            }
            if (stamp[j] != target[i + j]) {
                return false;
            }
            change = true;
        }
        if (change) {
            for (int j = 0; j < stamp.size(); ++j) {
                target[i + j] = '?';
            }
            result.push_back(i);
        }
        return change;
    }
};
