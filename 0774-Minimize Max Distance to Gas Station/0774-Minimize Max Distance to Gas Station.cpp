class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        double start = 0, end = stations[n - 1] - stations[0];
        while (end - start > 1e-6) {
            double mid = (start + end) / 2;
            int count = 0;
            for (int i = 1; i < n; ++i) {
                int dist = stations[i] - stations[i - 1];
                count += ceil(dist / mid) - 1;
            }
            if (count <= K) {
                end = mid;
            }
            else {
                start = mid;
            }            
        }
        
        return start;
    }
};
