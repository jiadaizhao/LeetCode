class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;
        while (i < n && digits[i] == 9)
        {
            digits[i] = 0;
            --i;
        }
        
        if (i >= 0)
        {
            ++digits[i];
        }
        else
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        
        return digits;
    }
};
