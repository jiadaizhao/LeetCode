class Solution {
    public int expressiveWords(String S, String[] words) {
        int count = 0, n = S.length();
        for (String word : words) {
            int i, j = 0;
            for (i = 0; i < n; ++i) {
                if (j < word.length() && S.charAt(i) == word.charAt(j)) {
                    ++j;
                }
                else if (i > 0 && S.charAt(i) == S.charAt(i - 1) && i < n - 1 && S.charAt(i) == S.charAt(i + 1)) {
                    ++i;
                }
                else if (!(i > 1 && S.charAt(i) == S.charAt(i - 1) && S.charAt(i) == S.charAt(i - 2))) {
                    break;
                }
            }
            if (i == n && j == word.length()) ++count;
        }
        return count;
    }
}
