class Solution {
public:
    string fractionAddition(string expression) {
        int i = 0;
        int n = expression.size();
        int sign = 1;
        int numerator = 0, denominator = 0;
        vector<int> result = {0, 1};
        while (i < n) {
            if (expression[i] == '-') {
                sign = -1;
                ++i;
            }
            else if (expression[i] == '+') {
                ++i;
            }
            
            while (i < n && isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i++] - '0');
            }
            
            ++i; // '/'
            
            while (i < n && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i++] - '0');
            }
            
            result = fractionSum(result[0], result[1], sign * numerator, denominator);
            sign = 1;
            numerator = 0;
            denominator = 0;            
        }
        
        return to_string(result[0]) + '/' + to_string(result[1]);
    }
    
private:
    vector<int> fractionSum(int num1, int den1, int num2, int den2) {
        vector<int> result(2);
        result[1] = den1 * den2;
        result[0] = num1 * den2 + num2 * den1;
        int gcd = GCD(result[0], result[1]);
        result[0] /= gcd;
        result[1] /= gcd;
        return result;
    }
    
    int GCD(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        
        return a;
    }
};
