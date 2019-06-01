class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low = 0, high = 0;
        for (int w : weights) {
            low = max(low, w);
            high += w;
        }

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 1, sum = 0;
            for (int w : weights) {
                sum += w;
                if (sum > mid) {
                    sum = w;
                    ++count;
                }
            }

            if (count <= D) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
