class Solution {
    public double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1;
        }
        double[] presum = new double[1 + N];
        presum[0] = 1;
        for (int i = 1; i <= N; ++i) {
            presum[i] = presum[i - 1];
            if (i > W) {
                presum[i] += (presum[i - 1] - presum[i - 1 - W]) / W;
            }
            else {
                presum[i] += presum[i - 1] / W;
            }
            if (i > K) {
                presum[i] -= (presum[i - 1] - presum[K - 1]) / W;
            }            
        }
        return presum[N] - presum[K - 1];
    }
}
