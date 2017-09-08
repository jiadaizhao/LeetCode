class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string result;
        int i = m - 1, j = n - 1;
        int carry = 0;
        int sum = 0;
        while (i >= 0 || j >= 0)
        {
            sum = carry;
            sum += (i >= 0) ? num1[i--] - '0' : 0;
            sum += (j >= 0) ? num2[j--] - '0' : 0;
            result += '0' + (sum % 10);
            carry = sum / 10;
        }
        
        if (carry)
        {
            result += '1';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
