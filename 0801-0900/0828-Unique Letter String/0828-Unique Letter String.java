class Solution {
    public int uniqueLetterString(String S) {
        int n = S.length();
        int[] last = new int[26], prev = new int[n], next = new int[n];
        Arrays.fill(last, -1);
        Arrays.fill(prev, -1);
        Arrays.fill(next, -1);
        for (int i = 0; i < n; ++i) {
            int index = S.charAt(i) - 'A';
            prev[i] = last[index];
            last[index] = i;            
        }
        
        Arrays.fill(last, -1);
        for (int i = n - 1; i >= 0; --i) {
            int index = S.charAt(i) - 'A';
            next[i] = last[index];
            last[index] = i;    
        }

        int count = 0, MOD = 1000000007;
        for (int i = 0; i < n; ++i) {
            int l1 = i - prev[i];
            int l2 = (next[i] == -1) ? n - i : next[i] - i;
            count = (count + l1 * l2) % MOD;
        }
        return count;
    }
}
