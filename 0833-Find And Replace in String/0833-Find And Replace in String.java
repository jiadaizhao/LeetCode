class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int n = S.length();
        int[] table = new int[n];
        Arrays.fill(table, -1);
        for (int i = 0; i < indexes.length; ++i) {
            boolean match = true;
            for (int j = 0; j < sources[i].length(); ++j) {
                if (indexes[i] + j >= S.length() || sources[i].charAt(j) != S.charAt(indexes[i] + j)) {
                    match = false;
                    break;
                }
            }
            if (match) {
                table[indexes[i]] = i;
            }
        }
        
        StringBuilder result = new StringBuilder();
        int i = 0;
        while (i < n) {
            if (table[i] != -1) {
                result.append(targets[table[i]]);
                i += sources[table[i]].length();
            }
            else {
                result.append(S.charAt(i++));
            }
        }
        
        return result.toString();
    }
}
