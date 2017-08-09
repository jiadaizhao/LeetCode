class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        int i = 0;
        int n = str.size();
        while (i < n && str[i] == ' ')
        {
            ++i;
        }
        
        if (i == n)
        {
            return 0;
        }
        
        int sign = 1;
        if (str[i] == '+')
        {
            ++i;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            ++i;
        }
        
        for (; i < n; ++i)
        {
            if (str[i] > '9' || str[i] < '0')
            {
                break;
            }
            
            result = result * 10 + (str[i] - '0');
            if (result > INT_MAX)
            {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }
        }
        
        return sign * result;
    }
};
