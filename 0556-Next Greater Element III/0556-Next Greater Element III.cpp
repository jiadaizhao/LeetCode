class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        if (str.size() == 1)
        {
            return -1;
        }
        int i = str.size() - 2;
        while (i >= 0 && str[i] >= str[i + 1])
        {
            --i;
        }
        if (i == -1)
        {
            return -1;
        }
        
        int j = str.size() - 1;
        while (j >= i && str[i] >= str[j])
        {
            --j;
        }
        
        swap(str[i], str[j]);
        reverse(str.begin() + i + 1, str.end());
        long long result = stol(str);
        if (result > INT_MAX)
        {
            return -1;
        }
        
        return result;
    }
};
