class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "")
        {
            return b;
        }
        else if (b == "")
        {
            return a;
        }
        
        string result;
        int carry = 0;
        while (a.size() || b.size())
        {
            int val1 = 0, val2 = 0;
            if (a.size())
            {
                val1 = a.back() - '0';
                a.pop_back();
            }
            if (b.size())
            {
                val2 = b.back() - '0';
                b.pop_back();
            }
            int sum = val1 + val2 + carry;
            carry = sum / 2;
            sum %= 2;
            result += '0' + sum;
        }
        
        if (carry)
        {
            result += '1';
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
