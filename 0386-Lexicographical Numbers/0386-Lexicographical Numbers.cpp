class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = curr;
            if (10 * curr <= n) {
                curr *= 10;
            }
            else {
                if (curr >= n) {
                    curr /= 10;
                }
                ++curr;
                while (curr % 10 == 0) {
                    curr /= 10;
                }
            }
        }
        
        return result;
    }
};
