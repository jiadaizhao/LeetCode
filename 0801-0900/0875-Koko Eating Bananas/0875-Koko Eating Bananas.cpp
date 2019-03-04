class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int pile : piles) {
                count += (pile + mid - 1) / mid;
            }
            if (count <= H) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
