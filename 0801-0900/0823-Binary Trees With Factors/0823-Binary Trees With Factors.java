class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        int MOD = 1000000007, n = A.length;
        Arrays.sort(A);
        Map<Integer, Integer> table = new HashMap();
        for (int i = 0; i < n; ++i) {
            table.put(A[i], i);
        }
        long[] dp = new long[n];
        long total = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < n; ++j) {
                if (A[i] % A[j] == 0) {
                    int num = A[i] / A[j];
                    if (table.containsKey(num)) {
                        dp[i] = (dp[i] + dp[j] * dp[table.get(num)]) % MOD;
                    }
                }
            }
            total = (total + dp[i]) % MOD;
        }
        return (int)total;
    }
}
