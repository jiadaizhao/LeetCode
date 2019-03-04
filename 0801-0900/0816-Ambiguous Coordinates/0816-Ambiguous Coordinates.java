import java.util.ArrayList;

class Solution {
    public List<String> ambiguousCoordinates(String S) {
        List<String> result = new ArrayList();
        int n = S.length();
        for (int i = 2; i < n - 1; ++i) {
            for (String s1 : parse(S.substring(1, i))) {
                for (String s2 : parse(S.substring(i, n - 1))) {
                    result.add("(" + s1 + ", " + s2 + ")");
                }
            }
        }
        return result;
    }

    private List<String> parse(String s) {
        List<String> result = new ArrayList();;
        for (int i = 1; i < s.length(); ++i) {
            String p1 = s.substring(0, i);
            String p2 = s.substring(i);
            if ((p1.length() == 1 || !p1.startsWith("0")) && !p2.endsWith("0")) {
                result.add(p1 + "." + p2);
            }
        }

        if (s.length() == 1 || !s.startsWith("0")) {
            result.add(s);
        }
        return result;
    }
}
