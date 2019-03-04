class Solution {
    public int numSimilarGroups(String[] A) {
        int n = A.length;
        int[] parents = new int[n];
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isSimilar(A[i], A[j])) {
                    int pa = findParent(parents, j);
                    int pb = findParent(parents, i);
                    parents[pb] = pa;
                }                
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (parents[i] == i) {
                ++count;
            }
        }
        return count;
    }
    
    private boolean isSimilar(String s, String t) {
        int diff = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != t.charAt(i)) {
                ++diff;
                if (diff > 2) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private int findParent(int[] parents, int i) {
        while (parents[i] != i) {
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return i;
    } 
}
