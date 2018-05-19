class Solution {
    public String toGoatLatin(String S) {
        StringBuilder result = new StringBuilder();
        int count = 0;
        for (String word : S.split(" ")) {
            ++count;
            if (isVowel(word.charAt(0))) {
                result.append(word);
            }
            else {
                result.append(word.substring(1));
                result.append(word.substring(0, 1));
            }
            result.append("ma");
            int j = count;
            while (j-- > 0) {
                result.append("a");
            }
            result.append(" ");
        }
        result.deleteCharAt(result.length() - 1);
        return result.toString();
    }
    
    private boolean isVowel(char c) {
        String target = "aeiou";
        return target.indexOf(Character.toLowerCase(c)) != -1;
    }
}
