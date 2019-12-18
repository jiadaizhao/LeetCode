class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> result;
        if (low == 0) result.push_back(0);
        queue<int> Q;
        for (int i = 1; i < 10; ++i) Q.push(i);
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            if (curr >= low && curr <= high) {
                result.push_back(curr);
            }
            if (curr <= high / 10) {
                int d = curr % 10;
                if (d > 0) Q.push(curr * 10 + d - 1);
                if (d < 9) Q.push(curr * 10 + d + 1);
            }
        }
        return result;
    }
};
