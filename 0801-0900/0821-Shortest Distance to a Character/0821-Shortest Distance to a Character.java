class Solution {
    public int[] shortestToChar(String S, char C) {
        int n = S.length();
        int[] result = new int[n];
        int prev = -n;
        for (int i = 0; i < n; ++i) {
            if (S.charAt(i) == C) {
                prev = i;
            }
            else {
                result[i] = i - prev;
            } 
        }
        
        prev = n * 2;
        for (int i = n - 1; i >= 0; --i) {
            if (S.charAt(i) == C) {
                prev = i;
            }
            else {
                result[i] = Math.min(result[i], prev - i);
            }   
        }
        return result;    
    }
}
