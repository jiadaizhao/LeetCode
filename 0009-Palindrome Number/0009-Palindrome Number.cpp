class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        
        int power = 1;
        while (x / power >= 10)
        {
            power *= 10;
        }
        
        while (power > 1)
        {
            int num1 = x % 10;
            int num2 = x / power;
            if (num1 != num2)
            {
                return false;
            }
            
            x = x % power / 10;
            power /= 100;
        }
        
        return true;
    }
};
