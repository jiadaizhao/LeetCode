class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> table = new HashMap();
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (table.containsKey(s.charAt(i)) && table.get(s.charAt(i)) >= start) {
                start = table.get(s.charAt(i)) + 1;
            }
            else {
                maxLen = Math.max(maxLen, i - start + 1);
            }
            table.put(s.charAt(i), i);
        }

        return maxLen;
    }
}
