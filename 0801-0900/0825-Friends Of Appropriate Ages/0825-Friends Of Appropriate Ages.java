class Solution {
    public int numFriendRequests(int[] ages) {
        int[] counts = new int[121], presum = new int[121];
        for (int age : ages) {
            ++counts[age];
        }
        for (int i = 1; i <= 120; ++i) {
            presum[i] = presum[i - 1] + counts[i];
        }
        
        int result = 0;
        for (int i = 15; i <= 120; ++i) {
            if (counts[i] == 0) {
                continue;
            }
            int count = presum[i] - presum[i / 2 + 7];
            result += count * counts[i] - counts[i];
        }
        return result;
    }
}
