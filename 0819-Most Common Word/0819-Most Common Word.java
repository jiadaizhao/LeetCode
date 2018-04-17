import java.util.HashMap;
import java.util.Map;
import java.util.Set;

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> ban = new HashSet();
        for (String s : banned) {
            ban.add(s);
        }

        Map<String, Integer> table = new HashMap();
        int n = paragraph.length(), i = 0;
        while (i < n && !Character.isLetter(paragraph.charAt(i))) {
            ++i;
        }

        String result = "";
        int maxCount = 0;
        StringBuilder s = new StringBuilder();
        while (i < n) {
            while (i < n && Character.isLetter(paragraph.charAt(i))) {
                s.append(Character.toLowerCase(paragraph.charAt(i++)));
            }

            String word = s.toString();
            if (!ban.contains(word)) {
                table.put(word, table.getOrDefault(word, 0) + 1);
                if (table.get(word) > maxCount) {
                    result = word;
                    maxCount = table.get(word);
                }
            }
            s = new StringBuilder();
            while (i < n && !Character.isLetter(paragraph.charAt(i))) {
                ++i;
            }
        }

        return result;
    }
}
