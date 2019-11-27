class Solution {
    public int consecutiveNumbersSum(int N) {
        int count = 1, i = 2;
        int left = N - i * (i - 1) / 2;
        while (left > 0) {
            if (left % i == 0) {
                ++count;
            }
            ++i;
            left = N - i * (i - 1) / 2;
        }
        
        return count;
    }
}
