class Solution {
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<List<Integer>>();
        for (int i = 0; i < N; ++i) {
            graph.add(new ArrayList<Integer>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        int[] sums = new int[N], counts = new int[N];
        Arrays.fill(counts, 1);
        dfs1(0, -1, graph, sums, counts);
        dfs2(0, -1, graph, sums, counts);
        return sums;
    }
    
    private void dfs1(int curr, int prev, List<List<Integer>> graph, int[] sums, int[] counts) {
        for (int next : graph.get(curr)) {
            if (next != prev) {
                dfs1(next, curr, graph, sums, counts);
                sums[curr] += sums[next] + counts[next];
                counts[curr] += counts[next];
            }
        }
    }
    
    private void dfs2(int curr, int prev, List<List<Integer>> graph, int[] sums, int[] counts) {
        for (int next : graph.get(curr)) {
            if (next != prev) {
                sums[next] = sums[curr] - counts[next] + graph.size() - counts[next];                
                dfs2(next, curr, graph, sums, counts);
            }
        }
    }
}
