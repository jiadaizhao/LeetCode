class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> result(n);
        int index = (a >= 0) ? n - 1 : 0;
        if (a >= 0) {
            while (left <= right) {
                int l = quad(nums[left], a, b, c);
                int r = quad(nums[right], a, b, c);
                if (l > r) {
                    result[index--] = l;
                    ++left;
                }
                else {
                    result[index--] = r;
                    --right;
                }
            }
        }
        else {
            while (left <= right) {
                int l = quad(nums[left], a, b, c);
                int r = quad(nums[right], a, b, c);
                if (l <= r) {
                    result[index++] = l;
                    ++left;
                }
                else {
                    result[index++] = r;
                    --right;
                }
            }
        }

        return result;
    }
    
private:
    int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};
