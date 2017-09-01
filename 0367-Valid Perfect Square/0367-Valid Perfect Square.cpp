class Solution {
public:
    bool isPerfectSquare(int num) {
        long start = 1, end = num / 2;
        while (start + 1 < end)
        {
            long mid = start + (end - start) / 2;
            long product = mid * mid;
            if (product < num)
            {
                start = mid;
            }
            else if (product > num)
            {
                end = mid;
            }
            else
            {
                return true;
            }
        }
        
        return (start * start == num) || (end * end == num);
    }
};
