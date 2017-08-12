class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> product(m + n);
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = (num1[i] - '0') * (num2[j] - '0') + product[p2];
                product[p1] += sum / 10;
                product[p2] = sum % 10;
            }
        }
        
        string result;
        for (int p : product)
        {
            if (result.size() || p != 0)
            {
                result += '0' + p;
            }
        }
        
        return result.size() ? result : "0";
    }
};
