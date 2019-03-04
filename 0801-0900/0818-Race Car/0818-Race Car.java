class Solution {
    public int racecar(int target) {
        memo = new int[1 + target];
        return dfs(target);
    }

    private int[] memo;
    private int dfs(int target) {
        if (memo[target] > 0) {
            return memo[target];
        }
        
        int n = (int)(Math.log(target) / Math.log(2)) + 1;
        if (1 << n == target + 1) {
            memo[target] = n;
        }
        else {
            memo[target] = dfs((1 << n) - 1 - target) + n + 1;
            for (int m = 0; m < n - 1; ++m) {
                memo[target] = Math.min(memo[target], dfs(target - (1 << (n - 1)) + (1 << m)) + n + m + 1);
            }                
        }
        return memo[target];
    }
}
