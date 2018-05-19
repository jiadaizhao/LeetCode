class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        int n = fronts.length;
        Set<Integer> table = new HashSet();
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                table.add(fronts[i]);
            }
        }
        
        int output = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            if (!table.contains(fronts[i])) {
                output = Math.min(output, fronts[i]);
            }
            if (!table.contains(backs[i])) {
                output = Math.min(output, backs[i]);
            }
        }
        return output == Integer.MAX_VALUE ? 0 : output;
    }
}
