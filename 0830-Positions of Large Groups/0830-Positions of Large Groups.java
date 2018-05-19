class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> result = new ArrayList();
        int n = S.length(), i = 0;
        while (i < n) {
            int start = i;
            while (i < n && S.charAt(i) == S.charAt(start)) {
                ++i;
            }
            if (i - start >= 3) {
                result.add(Arrays.asList(start, i - 1));
            }
        }
        return result;
    }
}
