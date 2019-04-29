class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int n = A.length;
        List<Integer> A1 = new ArrayList<>(), B1 = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    A1.add(i * n * 2 + j);
                }
                
                if (B[i][j] == 1) {
                    B1.add(i * n * 2 + j);
                }
            }
        }
                
        HashMap<Integer, Integer> table = new HashMap<>();
        
        for (int a : A1) {
            for (int b : B1) {
                table.put(a - b, table.getOrDefault(a - b, 0) + 1);
            }
        }
        
        int result = 0;
        for (int count : table.values()) {
            result = Math.max(result, count);
        }
            
        return result;
    }
}
