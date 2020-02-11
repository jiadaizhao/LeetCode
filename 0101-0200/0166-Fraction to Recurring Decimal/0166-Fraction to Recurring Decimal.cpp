class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if ((float)numerator / denominator < 0) {
            result += '-';
        }
        
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        
        result += to_string(num / den);
        long rem = num % den;
        if (rem == 0) {
            return result;
        }
        
        result += '.';
        unordered_map<long, int> table;        
        while(rem) {
            table[rem] = result.length();
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
            if (table.find(rem) != table.end()) {
                result.insert(table[rem], "(");
                result += ')';
                break;
            }
        }
        
        return result;        
    }
};
