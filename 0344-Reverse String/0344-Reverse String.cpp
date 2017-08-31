class Solution {
public:
    string reverseString(string s) {
        if (s.size() == 0)
        {
            return s;
        }
        
        int start = 0, end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            ++start;
            --end;
        }
        
        return s;
    }
};
