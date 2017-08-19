class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
        {
            return "0";
        }
        string result = "";
        if ((numerator > 0) ^ (denominator > 0))
        {
            result += '-';
        }
        
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        
        result += to_string(num / den);
        long rem = num % den;
        if (rem == 0)
        {
            return result;
        }
        
        result += '.';
        unordered_map<long, int> table;
        table[rem] = result.length();
        while(rem)
        {
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
            if (table.find(rem) != table.end())
            {
                int i = table[rem];
                result.insert(i, "(");
                result += ')';
                break;
            }
            else
            {
                table[rem] = result.length();
            }
        }
        
        return result;
        
    }
};
