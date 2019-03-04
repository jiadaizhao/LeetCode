class Solution {
    public boolean xorGame(int[] nums) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x == 0 || (nums.length & 1) == 0;
    }
}
