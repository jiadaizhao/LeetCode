class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int m = profit.length;
        Point[] jobs = new Point[m];
        for (int i = 0; i < m; ++i) {
            jobs[i] = new Point(difficulty[i], profit[i]);
        }
        Arrays.sort(jobs, (a, b) -> a.x - b.x);
        Arrays.sort(worker);
        int total = 0, i = 0, maxProfit = 0;
        for (int w : worker) {
            while (i < m && jobs[i].x <= w) {
                maxProfit = Math.max(maxProfit, jobs[i++].y);
            }
            total += maxProfit;
        }
        return total;
    }
}
