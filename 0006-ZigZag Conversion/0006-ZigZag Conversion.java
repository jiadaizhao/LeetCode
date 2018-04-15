class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        StringBuilder[] sb = new StringBuilder[numRows];
        for (int i = 0; i < sb.length; i++) {
            sb[i] = new StringBuilder();
        }
        int index = 0, step = 1;
        for (int i = 0; i < s.length(); ++i) {
            sb[index].append(s.charAt(i));
            if (index == 0)
                step = 1;
            else if (index == numRows - 1)
                step = -1;
            index += step;
        }
        
        for (int i = 1; i < sb.length; ++i) {
            sb[0].append(sb[i]);
        }
            
        return sb[0].toString();
    }
}
