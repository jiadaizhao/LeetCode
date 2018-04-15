class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] table = new int[256];
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++table[s.charAt(i)];
            while (table[s.charAt(i)] > 1) {
                --table[s.charAt(start++)];
            }
            maxLen = Math.max(maxLen, i - start + 1);
        }

        return maxLen;
    }
}
