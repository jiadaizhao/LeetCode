class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> table = new HashMap();
        for (String cpdomain : cpdomains) {
            int index = cpdomain.indexOf(' ');
            int num = Integer.parseInt(cpdomain.substring(0, index));
            String str = cpdomain.substring(index + 1);
            for (int i = str.length() - 1; i > 0; --i) {
                if (str.charAt(i) == '.') {
                    String s = str.substring(i + 1);
                    table.put(s, table.getOrDefault(s, 0) + num);
                }
            }
            table.put(str, table.getOrDefault(str, 0) + num);
        }        

        List<String> result = new ArrayList();
        for (String str : table.keySet()) {
            result.add(table.get(str) + " " + str);
        }
        return result;
    }
}
