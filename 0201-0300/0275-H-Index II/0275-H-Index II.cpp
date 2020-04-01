class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] == n - mid) {
                return n - mid;
            }
            else if (citations[mid] > n - mid) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return n - low;
    }
};
