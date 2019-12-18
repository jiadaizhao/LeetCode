class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int low = 1, high = accumulate(sweetness.begin(), sweetness.end(), 0) / (K + 1);
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            int count = 0, curr = 0;
            for (int s : sweetness) {
                curr += s;
                if (curr >= mid) {
                    if (++count >= K + 1) {
                        break;
                    }
                    curr = 0;
                }
            }
            
            if (count >= K + 1) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};
