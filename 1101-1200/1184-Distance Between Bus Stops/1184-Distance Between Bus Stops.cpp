class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            swap(start, destination);
        }
        int total = accumulate(distance.begin(), distance.end(), 0);
        int d = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        return min(d, total - d);
    }
};
