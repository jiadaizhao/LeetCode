class Solution {
    public String pushDominoes(String dominoes) {
        char[] result = dominoes.toCharArray();
        int last = -1;
        for (int i = 0; i < dominoes.length(); ++i) {
            if (dominoes.charAt(i) == 'L') {
                int j;
                if (last != -1 && dominoes.charAt(last) == 'R') {
                    j = (i + last) / 2;
                    if (((i + last) & 1) == 0) {
                        result[j] = '.';
                    }
                }
                else {
                    j = last;
                }
                Arrays.fill(result, j + 1, i, 'L');               
            }
            if (dominoes.charAt(i) != '.') {
                last = i;
            }
            else if (last != -1 && dominoes.charAt(last) == 'R') {
                result[i] = 'R';
            }
        }
        
        return String.valueOf(result);
    }
}
