class Solution {
public:
    string getHappyString(int n, int k) {
        int base = 1 << (n - 1);
        if (k > 3 * base) {
            return "";
        }
        
        vector<string> table = {"bc", "ac", "ab"};
        --k;
        int index = k / base;
        k %= base;
        string result = string(1, 'a' + index);
        base >>= 1;
        while (base > 0) {
            index = k / base;
            k %= base;
            result += table[result.back() - 'a'][index];
            base >>= 1;
        }
        
        return result;
    }
};
