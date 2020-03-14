class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int i = num1.size() - 1, j = num2.size() - 1;
        int sum = 0, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            sum = carry;
            sum += (i >= 0) ? num1[i--] - '0' : 0;
            sum += (j >= 0) ? num2[j--] - '0' : 0;
            result += '0' + (sum % 10);
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
